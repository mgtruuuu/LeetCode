class BoundedBlockingQueue {

  private:
    std::size_t mCapacity;
    std::size_t mFront = 0;
    std::size_t mRear = 0;
    int* mArr;
    std::condition_variable mCV;
    std::mutex mMutex;

  public:
    BoundedBlockingQueue(int capacity) : mCapacity{ std::size_t(capacity + 1) }
    {
        mArr = new (std::nothrow) int[mCapacity];

        if (mArr == nullptr) // handle case where new returned null
        {
            // Do error handling here
            std::cerr << "Could not allocate memory\n";
        }
    }
    
    void enqueue(int element)
    {
        {
            std::unique_lock<std::mutex> lk(mMutex);

            mCV.wait(lk, [this] { return isFull() == false; });

            mRear = (mRear + 1) % mCapacity;
            mArr[mRear] = element;
        }
        
        mCV.notify_all();       
    }

    int dequeue()
    {
        {
            std::unique_lock<std::mutex> lk(mMutex);

            mCV.wait(lk, [this] { return isEmpty() == false; });

            mFront = (mFront + 1) % mCapacity;
        }
        
        const auto res = mArr[mFront];
        
        mCV.notify_all();   
        
        return res;
    }

    int size()
    {
        if (mFront <= mRear) {
            return mRear - mFront;
        }
        else {
            return mCapacity + mRear - mFront;
        }
    }
    
    bool isEmpty() const
    {
        return mFront == mRear;
    }

    bool isFull() const
    {
        return (mRear + 1) % mCapacity == mFront;
    }

    ~BoundedBlockingQueue()
    {
        delete[] mArr;
        mArr = nullptr;
    }
};