///*
// Approach 1: Caching
class NumArray {
  public:
    NumArray(vector<int>& nums)
    {
        m_sums.clear();
        m_sums.resize(nums.size() + 1);

        m_sums[0] = 0;
        for (auto idx = 0; idx != static_cast<int>(nums.size()); ++idx) {
            m_sums[idx + 1] = m_sums[idx] + nums[idx];
        }
    }

    int sumRange(int left, int right)
    {
        return m_sums[right + 1] - m_sums[left];
    }

  private:
    std::vector<int> m_sums;
};
//*/



/*
// Approach 2: Caching
class NumArray {
  public:
    NumArray(vector<int>& nums)
    {
        m_sums.clear();
        m_sums = std::vector<std::vector<int>>(nums.size(), std::vector<int>(nums.size()));

        for (auto r = std::size_t(0); r != nums.size(); ++r) {

            m_sums[r][r] = nums[r];
            for (auto c = r + 1; c != nums.size(); ++c) {
                m_sums[r][c] = m_sums[r][c - 1] + nums[c];
            }
        }
    }

    int sumRange(int left, int right)
    {
        return m_sums[left][right];
    }

  private:
    std::vector<std::vector<int>> m_sums;
};
*/



/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */