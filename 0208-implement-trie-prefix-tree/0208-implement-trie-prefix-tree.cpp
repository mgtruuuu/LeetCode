class Trie {
  public:
    Trie() : m_children{ new Trie*[s_num_children]{} }, m_ending{ false }
    {
    }

    void insert(string word)
    {
        auto* p = this;
        for (const auto ch : word) {

            const auto idx = getIndex(ch);

            if (p->m_children[idx] == nullptr) {
                p->m_children[idx] = new Trie{};
            }

            p = p->m_children[idx];
        }

        p->m_ending = true;
    }

    Trie* searchHelper(const std::string& word)
    {
        auto* p = this;
        for (const auto ch : word) {

            const auto idx = getIndex(ch);
            p = p->m_children[idx];

            if (p == nullptr) {
                return p;
            }
        }

        return p;
    }

    bool search(string word)
    {
        auto* temp = searchHelper(word);

        return temp == nullptr ? false : temp->m_ending;
    }

    bool startsWith(string prefix)
    {
        return searchHelper(prefix);
    }

    ~Trie()
    {
        if (m_children != nullptr) {

            for (auto idx = 0; idx != s_num_children; ++idx) {

                if (m_children[idx] != nullptr) {
                    m_children[idx]->~Trie();
                }
            }

            delete[] m_children;
        }
    }

  private:
    std::size_t getIndex(const char ch)
    {
        return ch - 'a';
    }

    static constexpr int s_num_children = 'z' - 'a' + 1;
    Trie** m_children;
    bool m_ending;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */