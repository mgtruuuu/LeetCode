class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        std::vector<int> res(2);
        std::unordered_map<int, int> hash;

        auto idx = 0;
        while (true) {
            const auto ptr = hash.find(target - numbers[idx]);
            if (ptr != hash.end()) {

                res[0] = ptr->second;
                res[1] = idx;

                break;
            }

            hash.insert({ numbers[idx], idx });

            ++idx;
        }

        return res;
    }
};