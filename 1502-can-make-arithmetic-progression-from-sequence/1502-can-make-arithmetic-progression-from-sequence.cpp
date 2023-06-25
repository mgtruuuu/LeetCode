class Solution {
  public:
    bool canMakeArithmeticProgression(vector<int>& arr)
    {
        const auto len_arr = static_cast<int>(arr.size());

        const auto [p_min, p_max] = std::minmax_element(std::begin(arr), std::end(arr));
        const auto min = *p_min;
        const auto max = *p_max;

        if ((max - min) % (len_arr - 1) != 0) {
            return false;
        }

        const auto diff = (max - min) / (len_arr - 1);

        auto idx = 0;
        while (idx != len_arr) {

            if (arr[idx] == min + idx * diff) {
                ++idx;
            }
            else if ((arr[idx] - min) % diff != 0) {
                return false;
            }
            else {
                const auto idx_new = (arr[idx] - min) / diff;

                if (arr[idx] == arr[idx_new]) {
                    return false;
                }

                std::swap(arr[idx], arr[idx_new]);
            }
        }

        return true;
    }
};