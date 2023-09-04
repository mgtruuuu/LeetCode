class H2O {
  private:
    std::condition_variable mCV;
    std::mutex mMutex;
    int mCountH;
    int mCountO;
    int mReadyH;
    int mReadyO;

    void clearGroup()
    {
        if (2 <= mReadyH && 1 <= mReadyO) {
            mReadyH -= 2;
            mReadyO -= 1;
        }
    }

  public:
    H2O() : mCountH{ 0 }, mCountO{ 0 }, mReadyH{ 0 }, mReadyO{ 0 }
    {
    }

    void hydrogen(function<void()> releaseHydrogen)
    {
        {
            std::unique_lock<std::mutex> lk(mMutex);

            // mCV.wait(lk, [this] { return mCountH == 2; });
            while (2 * mCountO + 1 < mCountH) {
                mCV.wait(lk);
            }

            ++mCountH;

            // releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen();
            ++mReadyH;

            clearGroup();
        }

        mCV.notify_all();
    }

    void oxygen(function<void()> releaseOxygen)
    {
        {
            std::unique_lock<std::mutex> lk(mMutex);

            while (0 < 2 * mCountO - mCountH) {
                mCV.wait(lk);
            }

            ++mCountO;

            // releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen();
            ++mReadyO;

            clearGroup();
        }

        mCV.notify_all();
    }
};