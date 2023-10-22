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

            prev_key = keys[idx];
            ++idx;
        }

        return dp.back();
    }
};