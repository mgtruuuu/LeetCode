class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        const auto minus = std::numeric_limits<int>::min();
        
        auto count = 0;
        for (const auto& num : nums)
        {            
            if ((num & minus) != 0) {
                ++count;
            }
            else if (num == 0) {
                return 0;
            }
        }
        
        return (count % 2 == 0) ? 1 : -1;
    }
};