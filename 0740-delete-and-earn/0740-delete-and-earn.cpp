class Solution {
  public:
    int deleteAndEarn(vector<int>& nums)
    {
        std::unordered_map<int, int> num2count;

        auto min_num = INT_MAX;
        auto max_num = INT_MIN;
        for (const auto num : nums) {

            num2count[num] += num;

            if (num < min_num) {
                min_num = num;
            }

            if (max_num < num) {
                max_num = num;
            }
        }

        if (min_num == max_num) {
            return num2count[min_num];
        }

        const auto len_arr = max_num - min_num + 1;
        std::vector<int> arr(len_arr, 0);

        for (const auto& [k, v] : num2count) {
            arr[k - min_num] = v;
        }

        std::queue<int> dp;
        dp.push(arr[0]);
        dp.push(std::max(arr[0], arr[1]));

        auto idx = std::size_t(2);
        while (idx != len_arr) {

            const auto two_back = dp.front();

            dp.pop();
            dp.push(std::max(two_back + arr[idx++], dp.front()));
        }

        return dp.back();
    }
};