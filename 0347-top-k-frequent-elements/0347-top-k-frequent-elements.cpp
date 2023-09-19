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