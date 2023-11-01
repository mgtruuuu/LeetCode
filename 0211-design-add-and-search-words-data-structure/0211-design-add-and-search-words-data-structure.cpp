class WordDictionary {
  public:
    WordDictionary() : m_children{ new WordDictionary* [s_num_alphabets] {} }, m_done{ false }
    {
    }

    void addWordHelper(const std::string& word, const std::size_t idx_word)
    {
        if (idx_word == word.size()) {

            if (m_done == false) {
                m_done = true;
            }

            return;
        }

        const auto idx_children = getChildrenIndex(word[idx_word]);

        if (m_children[idx_children] == nullptr) {
            m_children[idx_children] = new WordDictionary{};
        }

        m_children[idx_children]->addWordHelper(word, idx_word + 1);
    }

    void addWord(string word)
    {
        addWordHelper(word, 0);
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
        else {

            const auto idx_children = getChildrenIndex(word[idx_word]);

            if (m_children[idx_children] == nullptr) {
                return false;
            }

            return m_children[idx_children]->searchHelper(word, idx_word + 1);
        }
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

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */