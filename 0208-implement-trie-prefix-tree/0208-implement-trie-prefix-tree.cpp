/*
// Approach 1 : Iteration
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
*/


///*
// Approach 2 : Recursion
class Trie {
  private:
    static constexpr int s_num_children = static_cast<int>('z') - static_cast<int>('a') + 1;
    Trie** m_children;
    bool m_is_done;

  public:
    Trie() : m_children{ new Trie* [s_num_children] {} }, m_is_done{ false }
    {
    }

    std::size_t getChildrenIndex(const char ch)
    {
        return ch - 'a';
    }

    void insertHelper(const std::string& word, const std::size_t idx_word)
    {
        if (idx_word == word.size()) {
            m_is_done = true;

            return;
        }

        const auto idx_children = getChildrenIndex(word[idx_word]);

        if (m_children[idx_children] == nullptr) {
            m_children[idx_children] = new Trie{};
        }

        m_children[idx_children]->insertHelper(word, idx_word + 1);
    }

    void insert(string word)
    {
        insertHelper(word, 0);
    }

    bool searchHelper(const std::string& word, const std::size_t idx_word)
    {
        if (idx_word == word.size()) {
            return m_is_done;
        }

        const auto idx_children = getChildrenIndex(word[idx_word]);

        if (m_children[idx_children] == nullptr) {
            return false;
        }

        return m_children[idx_children]->searchHelper(word, idx_word + 1);
    }

    bool search(string word)
    {
        return searchHelper(word, 0);
    }

    bool startsWithHelper(const std::string& word, const std::size_t idx_word)
    {
        if (idx_word == word.size()) {
            return true;
        }

        const auto idx_children = getChildrenIndex(word[idx_word]);

        if (m_children[idx_children] == nullptr) {
            return false;
        }

        return m_children[idx_children]->startsWithHelper(word, idx_word + 1);
    }

    bool startsWith(string prefix)
    {
        return startsWithHelper(prefix, 0);
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
//*/