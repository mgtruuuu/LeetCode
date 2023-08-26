class Solution {
  public:
    int maximumProduct(std::vector<int>& nums)
    {
        int min1 = std::numeric_limits<int>::max();
        int min2 = std::numeric_limits<int>::max();
        int max1 = std::numeric_limits<int>::min();
        int max2 = std::numeric_limits<int>::min();
        int max3 = std::numeric_limits<int>::min();
        
        for (int n : nums) {
            if (n <= min1) {
                min2 = min1;
                min1 = n;
            } else if (n <= min2) {
                min2 = n;
            }
            if (n >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n >= max2) {
                max3 = max2;
                max2 = n;
            } else if (n >= max3) {
                max3 = n;
            }
        }
        
        return std::max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
