///*
// Approach 1-1: Recursive
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

        m_children[idx_children]->eraseHelper(word, idx_word + 1);

        --m_num_prefixes;
        
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
//*/


/*
// Approach 1-2: Iterative
class Trie {
  public:
    Trie() : m_words_starting_here{ 0 }, m_words_ending_here{ 0 }, m_children{ new Trie* [s_num_children] {} }
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

            ++node->m_words_starting_here;

            node = node->m_children[idx];
        }

        ++node->m_words_ending_here;
        ++node->m_words_starting_here;
    }

    int countWordsEqualTo(string word)
    {
        return countWordsHelper(word) == nullptr ? 0 : countWordsHelper(word)->m_words_ending_here;
    }

    int countWordsStartingWith(string prefix)
    {
        return countWordsHelper(prefix) == nullptr ? 0 : countWordsHelper(prefix)->m_words_starting_here;
    }

    void erase(string word)
    {
        std::stack<std::pair<Trie*, int>> s;

        auto* node = this;

        for (const auto ch : word) {

            const auto idx = getChildrenIndex(ch);

            if (node->m_children[idx] == nullptr) {

                std::cerr << "Cannot find word : " << word << std::endl;

                while (s.empty() == false) {

                    s.top().first->m_words_starting_here;
                    s.pop();
                }

                return;
            }

            s.emplace(node, idx);

            --node->m_words_starting_here;

            node = node->m_children[idx];
        }

        --node->m_words_ending_here;
        --node->m_words_starting_here;

        bool is_node_empty = (node->m_words_starting_here == 0);
        while (s.empty() == false) {

            node = s.top().first;
            const auto idx_children = s.top().second;

            if (is_node_empty == true) {
                delete node->m_children[idx_children];
                node->m_children[idx_children] = nullptr;
            }

            is_node_empty = (node->m_words_starting_here == 0);

            s.pop();
        }
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
    Trie* countWordsHelper(const std::string& word)
    {
        auto* node = this;

        for (const auto ch : word) {

            const auto idx = getChildrenIndex(ch);

            if (node->m_children[idx] == nullptr) {
                return nullptr;
            }

            node = node->m_children[idx];
        }

        return node;
    }

    std::size_t getChildrenIndex(const char ch) const
    {
        return ch - 'a';
    }

    int m_words_starting_here;
    int m_words_ending_here;
    Trie** m_children;
    static constexpr int s_num_children = ('z' - 'a') + 1;
};
*/



/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */