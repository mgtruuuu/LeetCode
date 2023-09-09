class Solution {
  public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        std::unordered_map<int, int> num2count;
        for (const auto num : arr) {
            ++num2count[num];
        }

        // Store the frequency count of elements in the unordered set.
        std::unordered_set<int> hashset_freq;
        for (const auto& [key, value] : num2count) {
            hashset_freq.insert(value);
        }

        return (num2count.size() == hashset_freq.size());
    }
};