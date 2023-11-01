///*
// Approach 1: Trie - Recursion
class WordDictionary {
  public:
    WordDictionary() : m_children{ new WordDictionary* [s_num_alphabets] {} }, m_done{ false }
    {
    }

    void addWord(string word)
    {
        auto* node = this;

        for (const auto ch : word) {

            const auto idx = getChildrenIndex(ch);

            if (node->m_children[idx] == nullptr) {
                node->m_children[idx] = new WordDictionary{};
            }

            node = node->m_children[idx];
        }

        if (node->m_done == false) {
            node->m_done = true;
        }
    }

    bool searchHelper(const std::string& word, const std::size_t idx_word)
    {
        if (idx_word == word.size()) {
            return m_done;
        }

        if (word[idx_word] == '.') {

            for (auto idx = 0; idx != s_num_alphabets; ++idx) {

                if (m_children[idx] == nullptr) {
                    continue;
                }

                if (m_children[idx]->searchHelper(word, idx_word + 1) == true) {
                    return true;
                }
            }

            return false;
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

  private:
    std::size_t getChildrenIndex(const char ch)
    {
        return ch - 'a';
    }

    static constexpr int s_num_alphabets = 'z' - 'a' + 1;
    WordDictionary** m_children;
    bool m_done;
};
//*/