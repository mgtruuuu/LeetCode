class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        const auto zero = 0;
        const auto minus = std::numeric_limits<int>::min();
        
        auto res = 1;
        for (const auto& num : nums)
        {
            if (num & minus) {
                res *= (-1);
            }
            else if (!(num | zero)) {
                return 0;
            }
        }
        
        return res;
    }
};