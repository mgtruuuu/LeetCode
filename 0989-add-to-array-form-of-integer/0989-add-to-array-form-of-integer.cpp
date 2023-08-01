class Solution {
  public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        const auto len_num = static_cast<int>(num.size());
        auto cur = k;
        vector<int> ans;

        auto i = len_num;
        while (--i >= 0 || cur > 0) {
            if (i >= 0) {
                cur += num[i];
            }

            ans.push_back(cur % 10);
            cur /= 10;
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
