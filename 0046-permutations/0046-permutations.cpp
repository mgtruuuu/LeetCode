class Solution {

  private:
    void permuteRecursion(vector<int>& nums, const std::size_t left, const std::size_t right, std::vector<std::vector<int>>& permutations)
    {
        if (left == right) {

            permutations.push_back(nums);

            return;
        }

        for (auto i = left; i <= right; ++i) {

            std::swap(nums[left], nums[i]);
            permuteRecursion(nums, left + 1, right, permutations);
            std::swap(nums[left], nums[i]);
        }
    }

    std::size_t getFactorial(const std::size_t length);

  public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<std::vector<int>> permutations;
        permutations.reserve(getFactorial(nums.size()));

        permuteRecursion(nums, 0, nums.size() - 1, permutations);

        return permutations;
    }
};


std::size_t Solution::getFactorial(const std::size_t length)
{
    if (length <= 1) {
        return 1;
    }

    return getFactorial(length - 1) * length;
}