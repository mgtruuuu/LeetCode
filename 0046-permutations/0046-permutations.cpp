class Solution {

  private:
    void permuteRecursion(const std::size_t left, const std::size_t right, vector<int>& nums, std::vector<std::vector<int>>& permutations)
    {
        if (left == right) {

            permutations.push_back(nums);

            return;
        }

        for (auto i = left; i <= right; ++i) {

            std::swap(nums[left], nums[i]);
            permuteRecursion(left + 1, right, nums, permutations);
            std::swap(nums[left], nums[i]);
        }
    }

    std::size_t getFactorial(const std::size_t length);

  public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<std::vector<int>> permutations;
        permutations.reserve(getFactorial(nums.size()));

        permuteRecursion(0, nums.size() - 1, nums, permutations);

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