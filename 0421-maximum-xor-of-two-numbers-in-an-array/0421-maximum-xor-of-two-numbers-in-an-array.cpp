#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int findMaximumXOR(std::vector<int>& nums)
    {
        int maxNum = *std::max_element(nums.begin(), nums.end());
        int L = 0;
        while (maxNum) {
            maxNum >>= 1;
            L++;
        }

        int maxXor = 0, currXor;
        std::unordered_set<int> prefixes;
        for (int i = L - 1; i > -1; --i) {
            maxXor <<= 1;
            currXor = maxXor | 1;
            prefixes.clear();

            for (int num : nums)
                prefixes.insert(num >> i);

            for (int p : prefixes) {
                if (prefixes.count(currXor ^ p)) {
                    maxXor = currXor;
                    break;
                }
            }
        }
        return maxXor;
    }
};