class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if (nums2.empty() == true) {
            return;
        }
        
        auto p_marker = nums1.end() - 1;
        auto p_nums1 = nums1.end() - 1 - n;
        auto p_nums2 = nums2.end() - 1;

        while (nums1.begin() <= p_nums1) {

            if (*p_nums1 <= *p_nums2) {
                *p_marker = *p_nums2;
                --p_nums2;
            }
            else {
                *p_marker = *p_nums1;
                --p_nums1;
            }

            --p_marker;

            if (p_nums1 == p_marker) {
                return;
            }
        }

        while (nums2.begin() <= p_nums2) {
            *p_marker = *p_nums2;
            --p_nums2;
            --p_marker;
        }
    }
};