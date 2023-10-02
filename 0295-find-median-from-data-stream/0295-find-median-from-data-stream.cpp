/*
// Approach 2: Insertion Sort <------------ Time Limit Exceeded
class MedianFinder {
  private:
    std::vector<int> m_store; // resize-able container

  public:
    MedianFinder()
    {
    }

    // Adds a number into the data structure.
    void addNum(int num)
    {
        m_store.insert(lower_bound(m_store.begin(), m_store.end(), num), num); // binary search and insertion combined
    }

    double findMedian()
    {
        const auto len = m_store.size();
        return len & 1 ? m_store[len / 2] : (static_cast<double>(m_store[(len / 2) - 1]) + m_store[len / 2]) * 0.5;
    }
};
*/


/*
// Approach 3: Two Heaps
class MedianFinder {
  private:
    std::priority_queue<int> m_pq_low;                                       // 5 1 2 3 4
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_pq_high; // 7 10 8 14 21

  public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        m_pq_low.push(num);
        m_pq_high.push(m_pq_low.top());
        m_pq_low.pop();

        if (m_pq_low.size() < m_pq_high.size()) {

            m_pq_low.push(m_pq_high.top());
            m_pq_high.pop();
        }
    }

    double findMedian()
    {
        return m_pq_low.size() == m_pq_high.size() ? (m_pq_low.top() + m_pq_high.top()) / 2.0
                                                   : static_cast<double>(m_pq_low.top());
    }
};
*/


class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;

public:
    MedianFinder()
        : lo_median(data.end())
        , hi_median(data.end())
    {
    }

    void addNum(int num)
    {
        const size_t n = data.size();   // store previous size

        data.insert(num);               // insert into multiset

        if (!n) {
            // no elements before, one element now
            lo_median = hi_median = data.begin();
        }
        else if (n & 1) {
            // odd size before (i.e. lo == hi), even size now (i.e. hi = lo + 1)

            if (num < *lo_median)       // num < lo
                lo_median--;
            else                        // num >= hi
                hi_median++;            // insertion at end of equal range
        }
        else {
            // even size before (i.e. hi = lo + 1), odd size now (i.e. lo == hi)

            if (num > *lo_median && num < *hi_median) {
                lo_median++;                    // num in between lo and hi
                hi_median--;
            }
            else if (num >= *hi_median)         // num inserted after hi
                lo_median++;
            else                                // num <= lo < hi
                lo_median = --hi_median;        // insertion at end of equal range spoils lo
        }
    }

    double findMedian()
    {
        return ((double) *lo_median + *hi_median) * 0.5;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */