/*
// Approach 1: Vertical scanning
// TC: O(S), where S is the sum of all characters in all strings
// SC: O(1)
class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs)
    {
        auto res = std::string{};

        const auto& str_front = strs.front();

        for (auto idx_front = std::size_t(0); idx_front != str_front.size(); ++idx_front) {

            for (auto idx_strs = std::size_t(1); idx_strs != strs.size(); ++idx_strs) {

                if (idx_front == strs[idx_strs].size() || str_front[idx_front] != strs[idx_strs][idx_front]) {
                    return res;
                }
            }

            res.push_back(str_front[idx_front]);
        }

        return res;
    }
};
*/


// Approach 2: Divide and conquer
// In the worst case we have n equal strings with length m.
// TC: O(S), where S is the sum of all characters in all strings
// SC: O(S) = 2 * T(n/2) + O(m)
class Solution {
  private:
    std::string longestCommonPrefixHelper(const std::vector<std::string>& strs, const std::size_t idx_left,
                                          const std::size_t idx_right)
    {
        if (idx_left == idx_right) {
            return strs[idx_left];
        }

        const auto mid = idx_left + (idx_right - idx_left) / 2;

        const auto& lcp_left = longestCommonPrefixHelper(strs, idx_left, mid);
        const auto& lcp_right = longestCommonPrefixHelper(strs, mid + 1, idx_right);
        return commonPrefix(lcp_left, lcp_right);
    }

    std::string commonPrefix(const std::string& lhs, const std::string& rhs)
    {
        const auto n = std::min(lhs.size(), rhs.size());
        auto idx = 0;
        for (; idx != n; ++idx) {
            if (lhs[idx] != rhs[idx]) {
                break;
            }
        }

        return lhs.substr(0, idx);
    }

  public:
    string longestCommonPrefix(vector<string>& strs)
    {
        return longestCommonPrefixHelper(strs, 0, strs.size() - 1);
    }
};

