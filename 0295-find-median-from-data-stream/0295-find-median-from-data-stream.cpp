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



/*
// Approach 4: Multiset and Two Pointers
class MedianFinder {
    std::multiset<int> m_data;
    std::multiset<int>::iterator lo_median;
    std::multiset<int>::iterator hi_median;

  public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        const auto len = m_data.size(); // store previous size

        m_data.insert(num); // insert into multiset

        if (len & 1) {

            if (num < *lo_median) {
                lo_median--;
            }
            else {
                hi_median++; // insertion at end of equal range
            }
        }
        else if (len != 0) {

            // even size before (i.e. hi = lo + 1), odd size now (i.e. lo == hi)
            if (num > *lo_median && num < *hi_median) {
                lo_median++; // num in between lo and hi
                hi_median--;
            }
            // num inserted after hi
            else if (num >= *hi_median) {
                lo_median++;
            }
            // num <= lo < hi
            else {
                lo_median = --hi_median; // insertion at end of equal range spoils lo
            }
        }
        else {
            // no elements before, one element now
            lo_median = hi_median = m_data.begin();
        }
    }

    double findMedian()
    {
        return (static_cast<double>(*lo_median) + *hi_median) * 0.5;
    }
};
*/


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */