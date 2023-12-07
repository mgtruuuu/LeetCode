class Trie {
  public:
    Trie() : m_children{ new Trie* [s_num_children] {} }, m_starting{ 0 }, m_ending{ 0 }
    {
    }

    void insert(string word)
    {
        // insertRecursive(word);
        insertIterative(word);
    }

    int countWordsEqualTo(string word)
    {
        // return countWordsEqualToRecursive(word);
        return countWordsEqualToIterative(word);
    }

    int countWordsStartingWith(string prefix)
    {
        // return countWordsStartingWithRecursive(prefix);
        return countWordsStartingWithIterative(prefix);
    }

    void erase(string word)
    {
        return eraseRecursive(word);
        //return eraseIterative(word);
    }

    ~Trie()
    {
        for (auto idx = 0; idx != s_num_children; ++idx) {

            if (m_children[idx] != nullptr) {
                m_children[idx]->~Trie();
            }
        }

        delete[] m_children;
        m_children = nullptr;
    }

    void insertRecursive(const std::string& word, const std::size_t idx_word = 0);
    Trie* countWordsRecursiveHelper(const std::string& word, const std::size_t idx_word = 0);
    int countWordsEqualToRecursive(const std::string& word);
    int countWordsStartingWithRecursive(const std::string& prefix);
    void eraseRecursive(const std::string& word, const std::size_t idx_word = 0);

    void insertIterative(const std::string& word);
    Trie* countWordsIterativeHelper(const std::string& word);
    int countWordsEqualToIterative(const std::string& word);
    int countWordsStartingWithIterative(const std::string& prefix);
    void eraseIterative(const std::string& word);

  private:
    std::size_t getIndex(const char ch)
    {
        return ch - 'a';
    }

    static constexpr int s_num_children = 'z' - 'a' + 1;
    Trie** m_children;
    int m_starting;
    int m_ending;
};

void Trie::insertRecursive(const std::string& word, const std::size_t idx_word)
{
    m_starting += 1;

    if (word.size() == idx_word) {

        m_ending += 1;

        return;
    }

    const auto idx = getIndex(word[idx_word]);

    if (m_children[idx] == nullptr) {
        m_children[idx] = new Trie{};
    }

    m_children[idx]->insertRecursive(word, idx_word + 1);
}

void Trie::insertIterative(const std::string& word)
{
    auto* p = this;
    for (const auto ch : word) {

        const auto idx = getIndex(ch);

        if (p->m_children[idx] == nullptr) {
            p->m_children[idx] = new Trie{};
        }

        ++(p->m_starting);

        p = p->m_children[idx];
    }

    ++(p->m_starting);
    ++(p->m_ending);
}

Trie* Trie::countWordsIterativeHelper(const std::string& word)
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

int Trie::countWordsEqualToIterative(const std::string& word)
{
    auto* temp = countWordsIterativeHelper(word);

    return temp ? temp->m_ending : false;
}

Trie* Trie::countWordsRecursiveHelper(const std::string& word, const std::size_t idx_word)
{
    if (word.size() == idx_word) {
        return this;
    }

    const auto idx = getIndex(word[idx_word]);

    return m_children[idx] ? m_children[idx]->countWordsRecursiveHelper(word, idx_word + 1) : nullptr;
}

int Trie::countWordsEqualToRecursive(const std::string& word)
{
    auto* temp = countWordsRecursiveHelper(word);

    return temp ? temp->m_ending : 0;
}

int Trie::countWordsStartingWithRecursive(const std::string& prefix)
{
    auto* temp = countWordsRecursiveHelper(prefix);

    return temp ? temp->m_starting : 0;
}

int Trie::countWordsStartingWithIterative(const std::string& prefix)
{
    auto* temp = countWordsIterativeHelper(prefix);

    return temp ? temp->m_starting : 0;
}

void Trie::eraseRecursive(const std::string& word, const std::size_t idx_word)
{
    --m_starting;

    if (word.size() == idx_word) {

        --m_ending;

        return;
    }

    const auto idx = getIndex(word[idx_word]);

    m_children[idx]->eraseRecursive(word, idx_word + 1);

    if (m_children[idx]->m_starting == 0) {

        delete[] m_children[idx]->m_children;
        m_children[idx] = nullptr;
    }
}

// void Trie::eraseIterative(const std::string& word)
// {
//     std::stack<Trie*> s;

//     {
//         auto* p = this;
//         s.push(p);
//         --(p->m_starting);

//         for (const auto ch : word) {

//             const auto idx = getIndex(ch);
//             p = p->m_children[idx];

//             s.push(p);
//             --(p->m_starting);
//         }

//         --(p->m_ending);
//     }

//     auto* prev = s.top();
//     s.pop();

//     while (s.empty() == false) {

//         auto* curr = s.top();
//         s.pop();

//         if (prev->m_starting == 0) {

//             delete[] prev->m_children;
//             prev->m_children = nullptr;
//         }

//         prev = curr;
//     }
// }

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */