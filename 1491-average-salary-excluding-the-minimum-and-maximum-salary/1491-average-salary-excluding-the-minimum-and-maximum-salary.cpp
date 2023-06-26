class Solution {
  public:
    double average(vector<int>& salary)
    {
        auto sum = 0;
        auto max = std::numeric_limits<int>::min();
        auto min = std::numeric_limits<int>::max();

        for (const auto& ele : salary) {
            sum += ele;
            if (max < ele) {
                max = ele;
            }
            if (ele < min) {
                min = ele;
            }
        }

        return (sum - min - max) / (static_cast<double>(salary.size()) - 2.0);
    }
};