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

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        while (mFinished == false) {

            {
                std::unique_lock<std::mutex> lk(mMutex);

                while (!(isCountMultipleOf3() && !isCountMultipleOf5())) {

                    if (mFinished) {
                        // printf("fizz() ended\n");
                        return;
                    }

                    mCV.wait(lk);
                }

                printFizz();
                // printf("printFizz() called\t%d\n", mCount);

                countCheck();
            }

            mCV.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        while (mFinished == false) {

            {
                std::unique_lock<std::mutex> lk(mMutex);

                while (!(mCount % 3 != 0 && mCount % 5 == 0)) {

                    if (mFinished) {
                        // printf("buzz() ended\n");
                        return;
                    }

                    mCV.wait(lk);
                }

                printBuzz();
                // printf("printBuzz() called\t%d\n", mCount);

                countCheck();
            }

            mCV.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        while (mFinished == false) {

            {
                std::unique_lock<std::mutex> lk(mMutex);

                while (!(mCount % 3 == 0 && mCount % 5 == 0)) {

                    if (mFinished) {
                        // printf("fizzbuzz() ended\n");
                        return;
                    }

                    mCV.wait(lk);
                }

                printFizzBuzz();
                // printf("printFizzBuzz() called\t%d\n", mCount);

                countCheck();
            }

            mCV.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        while (mFinished == false) {

            {
                std::unique_lock<std::mutex> lk(mMutex);

                while (!(mCount % 3 != 0 && mCount % 5 != 0)) {

                    if (mFinished) {
                        // printf("number() ended\n");
                        return;
                    }

                    mCV.wait(lk);
                }

                printNumber(mCount);
                // printf("printNumber(%d) called\n", mCount);

                countCheck();
            }

            mCV.notify_all();
        }
    }
};