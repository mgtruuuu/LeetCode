class Solution {

  private:
    std::vector<std::vector<int>> permutations;

    void permuteRecursion(vector<int>& nums, const std::size_t left, const std::size_t right)
    {
        if (left == right) {

            permutations.push_back(nums);

            return;
        }

        for (auto i = left; i <= right; ++i) {

            std::swap(nums[left], nums[i]);
            permuteRecursion(nums, left + 1, right);
            std::swap(nums[left], nums[i]);
        }
    }

    std::size_t getFactorial(const std::size_t length)
    {
        if (length <= 1) {
            return 1;
        }

        return getFactorial(length - 1) * length;
    }

  public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        permutations.reserve(getFactorial(nums.size()));

        permuteRecursion(nums, 0, nums.size() - 1);

        return permutations;
    }
};