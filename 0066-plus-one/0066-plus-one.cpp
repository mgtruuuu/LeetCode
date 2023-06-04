class Solution {
  public:
    vector<int> plusOne(vector<int>& digits)
    {
        auto idx = static_cast<int>(digits.size()) - 1;

        if (digits[idx] != 9) {

            std::vector<int> res(digits.size());
            memcpy(res.data(), digits.data(), sizeof(int) * digits.size());
            res[digits.size() - 1] += 1;

            return res;
        }

        std::vector<int> temp(digits.size(), 0);
        --idx;

        while (0 <= idx) {

            if (digits[idx] != 9) {
                temp[idx] = digits[idx] + 1;

                memcpy(temp.data(), digits.data(), sizeof(int) * idx);

                return temp;
            }

            --idx;
        }

        std::vector<int> res(digits.size() + 1, 0);
        res[0] = 1;
        return res;
    }
};