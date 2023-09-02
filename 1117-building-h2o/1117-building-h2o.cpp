class H2O {
    atomic<int> qwq = 0;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        int tmp = 0;
        while (!qwq.compare_exchange_weak(tmp, tmp + 1, memory_order_acquire, memory_order_relaxed)){
            if (tmp == 1) tmp = 2;
            else if (tmp > 2) tmp = 0;
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        qwq.store(qwq + 1, memory_order_release); // no need to be atomic
    }

    void oxygen(function<void()> releaseOxygen) {
        int tmp = 4;
        while (!qwq.compare_exchange_weak(tmp, 5, memory_order_acquire, memory_order_relaxed)){
            tmp = 4;
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        qwq.store(0, memory_order_release);
    }
};