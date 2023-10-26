///*//*/
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