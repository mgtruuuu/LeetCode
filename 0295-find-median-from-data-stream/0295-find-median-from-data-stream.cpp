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

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */