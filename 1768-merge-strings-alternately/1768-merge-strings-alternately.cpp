class Solution {
  public:
    string mergeAlternately(string word1, string word2)
    {
        std::string res;
        const auto min = word1.size() < word2.size() ? word1.size() : word2.size();
        const auto len = word1.size() + word2.size();
        res.reserve(len);

        auto idx_word1 = word1.begin();
        auto idx_word2 = word2.begin();
        
        while (idx_word1 != word1.end() || idx_word2 != word2.end()) {
            
            if (idx_word1 != word1.end()) {
                res.push_back(*idx_word1);    
                ++idx_word1;
            }
            
            if (idx_word2 != word2.end()) {
                res.push_back(*idx_word2);    
                ++idx_word2;
            }
        }
        
        return res;
    }
};