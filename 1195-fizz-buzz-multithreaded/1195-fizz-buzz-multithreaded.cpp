class FizzBuzz {
  private:
    int n;
    int mCount = 1;
    bool mFinished = false;
    std::mutex mMutex;
    std::condition_variable mCV;

  public:
    FizzBuzz(int n)
    {
        this->n = n;
    }

    void countCheck()
    {
        if (mCount < n) {
            ++mCount;
        }
        else {
            mFinished = true;
        }
    }

    bool isCountMultipleOf3() const
    {
        return mCount % 3 == 0;
    }

    bool isCountMultipleOf5() const
    {
        return mCount % 5 == 0;
    }

    void helper(function<void()> printFunc, const bool isMultipleOf3, const bool isMultipleOf5)
    {
        while (mFinished == false) {

            {
                std::unique_lock<std::mutex> lk(mMutex);

                while (!(isCountMultipleOf3() == isMultipleOf3 && isCountMultipleOf5() == isMultipleOf5)) {

                    if (mFinished) {
                        // printf("fizz() ended\n");
                        return;
                    }

                    mCV.wait(lk);
                }

                printFunc();
                // printf("printFizz() called\t%d\n", mCount);

                countCheck();
            }

            mCV.notify_all();
        }
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        helper(printFizz, true, false);
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        helper(printBuzz, false, true);
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        helper(printFizzBuzz, true, true);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        helper([this, &printNumber] { printNumber(mCount); }, false, false);
    }
};