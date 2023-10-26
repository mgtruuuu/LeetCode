/*
// Approach 1: Breadth-First Search
class Solution {
  public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        const auto len_s = static_cast<int>(s.size());

        std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());
        std::queue<int> q;
        std::vector<bool> seen(len_s + 1, false);
        q.push(0);
        seen[0] = true;

        while (q.empty() == false) {

            const auto start = q.front();
            q.pop();

            if (start == len_s) {
                return true;
            }

            for (auto end = start + 1; end <= len_s; ++end) {

                if (seen[end] == true) {
                    continue;
                }

                if (words.find(s.substr(start, end - start)) != words.end()) {

                    q.push(end);
                    seen[end] = true;
                }
            }
        }

        return false;
    }
};
*/


class Solution {
  private:
    bool dp(const std::string& s, const std::vector<std::string>& word_dict, const int i, std::vector<int>& memo)
    {
        if (i == -1) {
            return true;
        }
        // if (i < 0) {
        //     return true;
        // }

        if (memo[i] != -1) {
            return memo[i] == 1; // true
        }

        for (const auto& word : word_dict) {

            const auto len_word = static_cast<int>(word.length());

            // i + 1 - len_word < 0 : Handle out of bounds case
            if (i + 1 - len_word >= 0 && s.substr(i + 1 - len_word, len_word) == word &&
                dp(s, word_dict, i - len_word, memo) == true) {

                memo[i] = 1; // true
                return true;
            }
        }

        memo[i] = 0; // false
        return false;
    }

  public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        auto memo = std::vector(s.length(), -1);

        return dp(s, wordDict, s.length() - 1, memo);
    }
};