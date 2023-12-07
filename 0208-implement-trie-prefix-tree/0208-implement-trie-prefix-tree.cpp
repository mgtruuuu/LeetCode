class Trie {
  public:
    Trie() : m_children{ new Trie* [s_num_children] {} }, m_ending{ false }
    {
    }

    void insert(string word)
    {
        insertRecursive(word);
        // insertIterative(word);
    }

    bool search(string word)
    {
        return searchRecursive(word);
        // return searchIteration(word);
    }

    bool startsWith(string prefix)
    {
        return searchRecursiveHelper(prefix, 0);
        // return searchIterationHelper(prefix);
    }

    ~Trie()
    {
        for (auto idx = 0; idx != s_num_children; ++idx) {

            if (m_children[idx] != nullptr) {
                m_children[idx]->~Trie();
            }
        }

        delete[] m_children;
    }

    void insertRecursiveHelper(const std::string& word, const std::size_t idx_word);
    void insertRecursive(const std::string& word);
    void insertIterative(const std::string& word);
    Trie* searchIterationHelper(const std::string& word);
    bool searchIteration(string word);
    Trie* searchRecursiveHelper(const std::string& word, const std::size_t idx_word);
    bool searchRecursive(const std::string& word);

  private:
    std::size_t getIndex(const char ch)
    {
        return ch - 'a';
    }

    static constexpr int s_num_children = 'z' - 'a' + 1;
    Trie** m_children;
    bool m_ending;
};

void Trie::insertRecursiveHelper(const std::string& word, const std::size_t idx_word)
{
    if (word.size() == idx_word) {

        m_ending = true;

        return;
    }

    const auto idx = getIndex(word[idx_word]);

    if (m_children[idx] == nullptr) {
        m_children[idx] = new Trie{};
    }

    m_children[idx]->insertRecursiveHelper(word, idx_word + 1);
}

void Trie::insertRecursive(const std::string& word)
{
    insertRecursiveHelper(word, 0);
}

void Trie::insertIterative(const std::string& word)
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

Trie* Trie::searchIterationHelper(const std::string& word)
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

bool Trie::searchIteration(string word)
{
    auto* temp = searchIterationHelper(word);

    return temp ? temp->m_ending : false;
}

Trie* Trie::searchRecursiveHelper(const std::string& word, const std::size_t idx_word)
{
    if (word.size() == idx_word) {
        return this;
    }

    const auto idx = getIndex(word[idx_word]);

    return m_children[idx] ? m_children[idx]->searchRecursiveHelper(word, idx_word + 1) : nullptr;
}

bool Trie::searchRecursive(const std::string& word)
{
    auto* temp = searchRecursiveHelper(word, 0);

    return temp ? temp->m_ending : false;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */