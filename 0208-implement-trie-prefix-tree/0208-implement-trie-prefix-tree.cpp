class Trie {
  private:
    static constexpr int s_num_children = static_cast<int>('z') - static_cast<int>('a') + 1;
    Trie** m_children;
    bool m_is_done;

  public:
    Trie()
    {
        m_children = new Trie*[s_num_children];

        for (auto i = 0; i != s_num_children; ++i) {
            m_children[i] = nullptr;
        }

        m_is_done = false;
    }

    void insert(string word)
    {
        auto* node = this;

        for (const auto ch : word) {

            const auto idx = static_cast<int>(ch) - static_cast<int>('a');

            if (node->m_children[idx] == nullptr) {
                node->m_children[idx] = new Trie{};
            }
            
            node = node->m_children[idx];
        }

        node->m_is_done = true;
    }

    bool search(string word)
    {
        auto* node = this;

        for (const auto ch : word) {

            const auto idx = static_cast<int>(ch) - static_cast<int>('a');

            if (node->m_children[idx] == nullptr) {
                return false;
            }

            node = node->m_children[idx];
        }

        return node->m_is_done;
    }

    bool startsWith(string prefix)
    {
        auto* node = this;

        for (const auto ch : prefix) {

            const auto idx = static_cast<int>(ch) - static_cast<int>('a');

            if (node->m_children[idx] == nullptr) {
                return false;
            }

            node = node->m_children[idx];
        }

        return true;
    }

    ~Trie()
    {
        for (auto i = 0; i != s_num_children; ++i) {
            if (m_children[i] != nullptr) {
                m_children[i]->~Trie();
            }
        }

        delete[] m_children;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */