class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> num2count;

        for (const auto num : nums) {
            ++num2count[num];
        }

        std::vector<int> res;
        res.reserve(k);

        std::priority_queue<std::pair<int, int>> pq;

        const auto len_nums = static_cast<int>(num2count.size());
        auto count = 0;

        for (const auto& [key_num, value_count] : num2count) {

            pq.push(std::make_pair(value_count, key_num));

            if (len_nums < k + count++) {

                res.push_back(pq.top().second);
                pq.pop();
            }
        }

        res.push_back(pq.top().second);
        return res;
    }
};

/*
class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        if (k == static_cast<int>(nums.size())) {
            return nums;
        }

        std::unordered_map<int, int> num2count;
        for (const auto num : nums) {
            ++num2count[num];
        }

        const auto comp = [&num2count](const int k1, const int k2) { return num2count[k1] < num2count[k2]; };

        std::vector<int> keys;
        keys.reserve(num2count.size());

        for (const auto& [key_num, value_count] : num2count) {
            keys.push_back(key_num);
        }

        for (auto i = 0; i != k; ++i) {

            std::make_heap(keys.begin(), keys.end() - i, comp);

            std::pop_heap(keys.begin(), keys.end() - i);
        }

        return std::vector(keys.end() - k, keys.end());
    }
};
*/