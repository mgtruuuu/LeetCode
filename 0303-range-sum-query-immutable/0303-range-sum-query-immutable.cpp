class NumArray {
  public:
    NumArray(vector<int>& nums)
    {
        m_nums.clear();
        m_nums.resize(nums.size() + 1);

        m_nums[0] = 0;
        for (auto idx = 1; idx != static_cast<int>(m_nums.size()); ++idx) {
            m_nums[idx] = m_nums[idx - 1] + nums[idx - 1];
        }
    }

    int sumRange(int left, int right)
    {
        return m_nums[right + 1] - m_nums[left];
    }

  private:
    std::vector<int> m_nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */