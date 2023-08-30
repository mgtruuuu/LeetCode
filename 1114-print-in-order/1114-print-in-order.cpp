class Foo {

  private:
    std::condition_variable mCV;
    std::mutex mMutex;
    int mCount = 0;

  public:
    Foo()
    {
    }

    void signals()
    {
        {
            std::lock_guard<std::mutex> lk(mMutex);
            ++mCount;
        }
        mCV.notify_all();
    }

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        signals();
    }

    void second(function<void()> printSecond)
    {
        std::unique_lock<std::mutex> lk(mMutex);

        mCV.wait(lk, [this] { return mCount == 1; });

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        lk.unlock();

        signals();
    }

    void third(function<void()> printThird)
    {
        std::unique_lock<std::mutex> lk(mMutex);

        mCV.wait(lk, [this] { return mCount == 2; });

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};