class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        auto idx_lhs = 0;
        auto idx_rhs = static_cast<int>(numbers.size()) - 1;

        while (idx_lhs <= idx_rhs) {

            const auto sum = numbers[idx_lhs] + numbers[idx_rhs];

            if (sum < target) {
                do {
                    ++idx_lhs;
                } while (numbers[idx_lhs - 1] == numbers[idx_lhs]);
            }
            else if (sum > target) {
                do {
                    --idx_rhs;
                } while (numbers[idx_rhs] == numbers[idx_rhs + 1]);
            }
            else {
                return vector<int>{ idx_lhs + 1, idx_rhs + 1 };
            }
        }

        return vector<int>(2);
    }
};