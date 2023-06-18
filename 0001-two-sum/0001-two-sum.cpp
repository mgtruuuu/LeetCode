class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        std::unordered_map<int, int> hash;

        for (auto idx = 0; idx != static_cast<int>(numbers.size()); ++idx) {
            const auto ptr = hash.find(target - numbers[idx]);
            if (ptr != hash.end()) {
                return std::vector<int>{ ptr->second, idx };
            }

            hash.insert({ numbers[idx], idx });
        }

        assert(false);
        return std::vector<int>{};
    }
};