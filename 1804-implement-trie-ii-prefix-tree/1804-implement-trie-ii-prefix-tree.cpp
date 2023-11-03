/*
// Approach 1 : Recursive
class Trie {
  public:
    Trie() : m_num_prefixes{ 0 }, m_num_instances{ 0 }, m_children{ new Trie* [s_num_children] {} }
    {
    }

    void insert(string word)
    {
        insertHelper(word, 0);
    }

    int countWordsEqualTo(string word)
    {
        return countWordsEqualToHelper(word, 0);
    }

    int countWordsStartingWith(string prefix)
    {
        return countWordsStartingWithHelper(prefix, 0);
    }

    void erase(string word)
    {
        eraseHelper(word, 0);
    }

    ~Trie()
    {
        if (m_children != nullptr) {

            for (auto i = 0; i != s_num_children; ++i) {

                if (m_children[i] != nullptr) {
                    m_children[i]->~Trie();
                }
            }

            delete[] m_children;
            m_children = nullptr;
        }
    }

  private:
    void insertHelper(const std::string& word, const std::size_t idx_word)
    {
        if (idx_word == word.size()) {

            ++m_num_prefixes;
            ++m_num_instances;

            return;
        }

        ++m_num_prefixes;

        const auto idx_children = getChildrenIndex(word[idx_word]);

        if (m_children[idx_children] == nullptr) {
            m_children[idx_children] = new Trie{};
        }

        m_children[idx_children]->insertHelper(word, idx_word + 1);
    }

    int countWordsEqualToHelper(const std::string& word, const std::size_t idx_word)
    {
        if (idx_word == word.size()) {
            return m_num_instances;
        }

        const auto idx_children = getChildrenIndex(word[idx_word]);

        return m_children[idx_children] == nullptr
                   ? 0
                   : m_children[idx_children]->countWordsEqualToHelper(word, idx_word + 1);
    }

    int countWordsStartingWithHelper(const std::string& prefix, const std::size_t idx_word)
    {
        if (idx_word == prefix.size()) {
            return m_num_prefixes;
        }

        const auto idx_children = getChildrenIndex(prefix[idx_word]);

        return m_children[idx_children] == nullptr
                   ? 0
                   : m_children[idx_children]->countWordsStartingWithHelper(prefix, idx_word + 1);
    }

    void eraseHelper(const std::string& word, const std::size_t idx_word)
    {
        if (idx_word == word.size()) {

            --m_num_instances;
            --m_num_prefixes;

            return;
        }

        const auto idx_children = getChildrenIndex(word[idx_word]);

        // if (m_children[idx_children] == nullptr) {

        //     std::cerr << "Nothing to erase word : " << word << std::endl;

        //     return;
        // }

        --m_num_prefixes;
        m_children[idx_children]->eraseHelper(word, idx_word + 1);

        if (m_num_prefixes == 0) {
            delete m_children[idx_children];
            m_children[idx_children] = nullptr;
        }
    }

    std::size_t getChildrenIndex(const char ch) const
    {
        return ch - 'a';
    }

    int m_num_prefixes;
    int m_num_instances;
    Trie** m_children;
    static constexpr int s_num_children = ('z' - 'a') + 1;
};
*/


class Trie {
  public:
    Trie() : m_num_prefixes{ 0 }, m_num_instances{ 0 }, m_children{ new Trie* [s_num_children] {} }
    {
    }

    void insert(string word)
    {
        auto* node = this;

        for (const auto ch : word) {

            const auto idx = getChildrenIndex(ch);

            if (node->m_children[idx] == nullptr) {
                node->m_children[idx] = new Trie{};
            }

            ++node->m_num_prefixes;

            node = node->m_children[idx];
        }

        ++node->m_num_instances;
        ++node->m_num_prefixes;
    }

    int countWordsEqualTo(string word)
    {
        auto* node = this;

        for (const auto ch : word) {

            const auto idx = getChildrenIndex(ch);

            if (node->m_children[idx] == nullptr) {
                return 0;
            }

            node = node->m_children[idx];
        }

        return node->m_num_instances;
    }

    int countWordsStartingWith(string prefix)
    {
        auto* node = this;

        for (const auto ch : prefix) {

            const auto idx = getChildrenIndex(ch);

            if (node->m_children[idx] == nullptr) {
                return 0;
            }

            node = node->m_children[idx];
        }

        return node->m_num_prefixes;
    }

    void erase(string word)
    {
        auto* node = this;

        for (const auto ch : word) {

            const auto idx = getChildrenIndex(ch);

            --node->m_num_prefixes;

            node = node->m_children[idx];
        }

        --node->m_num_instances;
        --node->m_num_prefixes;
    }

    ~Trie()
    {
        if (m_children != nullptr) {

            for (auto i = 0; i != s_num_children; ++i) {

                if (m_children[i] != nullptr) {
                    m_children[i]->~Trie();
                }
            }

            delete[] m_children;
            m_children = nullptr;
        }
    }

  private:
    std::size_t getChildrenIndex(const char ch) const
    {
        return ch - 'a';
    }

    int m_num_prefixes;
    int m_num_instances;
    Trie** m_children;
    static constexpr int s_num_children = ('z' - 'a') + 1;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */