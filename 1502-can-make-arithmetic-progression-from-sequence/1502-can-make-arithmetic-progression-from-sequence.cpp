class Solution {
  public:
    bool canMakeArithmeticProgression(vector<int>& arr)
    {
        std::set<int> arr_set;
        for (const auto& ele : arr) {
            arr_set.insert(ele);
        }

        if (arr_set.size() == 1) {
            return true;
        }
        else if (arr_set.size() < arr.size()) {
            return false;
        }

        auto p = arr_set.begin();
        auto prev = p;
        const auto difference = *(++p) - *prev;
        ++p;
        ++prev;

        while (p != arr_set.end()) {
            if (*p - *prev != difference) {
                return false;
            }

            ++p;
            ++prev;
        }

        return true;
    }
};