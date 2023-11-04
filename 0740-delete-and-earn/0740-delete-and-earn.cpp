///*
// Approach 1: Space Optimized Bottom-Up Dynamic Programming
class Solution {
  public:
    int deleteAndEarn(vector<int>& nums)
    {
        std::unordered_map<int, int> num2score;

        auto min_num = INT_MAX;
        auto max_num = INT_MIN;
        for (const auto num : nums) {

            num2score[num] += num;

            if (num < min_num) {
                min_num = num;
            }

            if (max_num < num) {
                max_num = num;
            }
        }

        if (min_num == max_num) {
            return num2score[min_num];
        }

        const auto len_arr = max_num - min_num + 1;

        std::queue<int> dp;
        dp.push(num2score[min_num]);
        dp.push(std::max(num2score[min_num], num2score[min_num + 1]));

        auto idx = std::size_t(2);
        while (idx != len_arr) {

            const auto two_back = dp.front();

            dp.pop();
            dp.push(std::max(two_back + num2score[min_num + idx++], dp.front()));
        }

        return dp.back();
    }
};
//*/


/*
// Approach 2: Iterate Over Elements
class Solution {
  public:
    int deleteAndEarn(vector<int>& nums)
    {
        std::unordered_map<int, int> num2score;
        for (const auto num : nums) {
            num2score[num] += num;
        }

        const auto len = num2score.size();
        if (len == std::size_t(1)) {
            return num2score.begin()->second;
        }

        std::vector<int> keys;
        keys.reserve(len);
        for (const auto& kv : num2score) {
            keys.push_back(kv.first);
        }
        std::sort(keys.begin(), keys.end());

        std::queue<int> dp;
        dp.push(num2score[keys.front()]);

        if (keys[1] - keys[0] == 1) {
            dp.push(std::max(num2score[keys[0]], num2score[keys[1]]));
        }
        else {
            dp.push(dp.front() + num2score[keys[1]]);
        }

        auto prev_key = keys[1];
        auto idx = std::size_t(2);
        while (idx != len) {

            const auto two_back = dp.front();
            dp.pop();

            if (keys[idx] - prev_key == 1) {
                dp.push(std::max(two_back + num2score[keys[idx]], dp.front()));
            }
            else {
                dp.push(dp.front() + num2score[keys[idx]]);
            }

            prev_key = keys[idx++];
        }

        return dp.back();
    }
};
*/