class RandomizedSet {
  public:
    std::unordered_set<int> m_set;

    RandomizedSet()
    {
        m_set.clear();
    }

    bool insert(int val)
    {
        if (m_set.find(val) == m_set.end()) {
            m_set.insert(val);
            return true;
        }
        else {
            return false;
        }
    }

    bool remove(int val)
    {
        auto ptr = m_set.find(val);

        if (ptr != m_set.end()) {
            m_set.erase(ptr);
            return true;
        }
        else {
            return false;
        }
    }

    int getRandom()
    {
        auto mt = std::mt19937{ static_cast<std::mt19937::result_type>(
            std::chrono::steady_clock::now().time_since_epoch().count()) };

        auto idx_distributor = std::uniform_int_distribution{ 0, static_cast<int>(m_set.size()) - 1 };

        auto ptr = m_set.begin();
        std::advance(ptr, idx_distributor(mt));
        
        return *ptr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */