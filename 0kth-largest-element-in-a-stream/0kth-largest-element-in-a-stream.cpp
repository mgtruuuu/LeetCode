class KthLargest {
  private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> larges;
    int kth;

  public:
    KthLargest(int k, vector<int>& nums) : kth{ k }
    {
        for (const auto num : nums) {

            larges.push(num);

            if (std::size_t(k) < larges.size()) {
                larges.pop();
            }
        }
    }

    int add(int val)
    {
        larges.push(val);
        
        if (std::size_t(kth) < larges.size()) {
            larges.pop();
        }

        return larges.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */