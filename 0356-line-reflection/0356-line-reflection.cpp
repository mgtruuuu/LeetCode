class Solution {
  private:
    int64_t get1DIndex(const std::vector<int>& point)
    {
        return point.front() + int64_t(100'000) * point.back();
    }

  public:
    bool isReflected(vector<vector<int>>& points)
    {
        std::unordered_map<int64_t, int> point2count;

        auto min = INT_MAX;
        auto max = INT_MIN;
        for (const auto& point : points) {

            ++point2count[get1DIndex(point)];

            if (min > point.front()) {
                min = point.front();
            }

            if (max < point.front()) {
                max = point.front();
            }
        }

        const auto x_middle_twice = (min + max);

        for (const auto& point : points) {

            if (point.front() < (x_middle_twice + 1) / 2 &&
                point2count.find(get1DIndex({ x_middle_twice - point.front(), point.back() })) == point2count.end()) {
                return false;
            }

            if (point.front() > (x_middle_twice - 1) / 2 &&
                point2count.find(get1DIndex({ x_middle_twice - point.front(), point.back() })) == point2count.end()) {
                return false;
            }
        }

        return true;
    }
};