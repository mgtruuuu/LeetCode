class Solution {
  public:
    int maximumProduct(std::vector<int>& nums)
    {
        auto min1 = std::numeric_limits<int>::max();
        auto min2 = std::numeric_limits<int>::max();
        auto max1 = std::numeric_limits<int>::min();
        auto max2 = std::numeric_limits<int>::min();
        auto max3 = std::numeric_limits<int>::min();

        for (const auto num : nums) {

            if (num <= min1) {

                min2 = min1;
                min1 = num;
            }
            else if (num <= min2) {

                min2 = num;
            }

            if (num >= max1) {

                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num >= max2) {

                max3 = max2;
                max2 = num;
            }
            else if (num >= max3) {
                max3 = num;
            }
        }

        return std::max(min1 * min2 * max1, max1 * max2 * max3);
    }
};