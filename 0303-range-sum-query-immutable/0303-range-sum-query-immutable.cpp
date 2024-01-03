class NumArray {
  public:
    NumArray(vector<int>& nums)
    {
        m_sums.clear();
        m_sums.resize(nums.size() + 1);

        m_sums[0] = 0;
        for (auto idx = 1; idx != static_cast<int>(m_sums.size()); ++idx) {
            m_sums[idx] = m_sums[idx - 1] + nums[idx - 1];
        }
    }

    int sumRange(int left, int right)
    {
        return m_sums[right + 1] - m_sums[left];
    }

  private:
    std::vector<int> m_sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */