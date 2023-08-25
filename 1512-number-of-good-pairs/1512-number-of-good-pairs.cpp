class Solution {
  public:
    int numIdenticalPairs(vector<int>& nums)
    {
        std::vector<int>::iterator itr1, itr2;
        int count = 0;
        for (itr1 = nums.begin(); itr1 != nums.end(); itr1++) {
            for (itr2 = itr1 + 1; itr2 != nums.end(); itr2++) {
                if (*itr1 == *itr2) {
                    count++;
                }
            }
        }
        return count;
    }
};
