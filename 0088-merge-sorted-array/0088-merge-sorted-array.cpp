/*
// Approach 1: Three Pointers (Start From the Beginning)
class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        std::vector<int> copy(m);
        if (m != 0) {
            memcpy(copy.data(), nums1.data(), m * sizeof(int));
        }

        std::size_t idx_copy = 0, idx_nums2 = 0, idx_nums1 = 0;
        while (idx_copy != copy.size() && idx_nums2 != nums2.size()) {
            copy[idx_copy] < nums2[idx_nums2] ? nums1[idx_nums1++] = copy[idx_copy++]
                                              : nums1[idx_nums1++] = nums2[idx_nums2++];
        }

        while (idx_copy != copy.size()) {
            nums1[idx_nums1++] = copy[idx_copy++];
        }

        while (idx_nums2 != nums2.size()) {
            nums1[idx_nums1++] = nums2[idx_nums2++];
        }
    }
};
*/

///*
// Approach 2: Three Pointers (Start From the End)
class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        auto idx = m + n - 1, idx_nums1 = m - 1, idx_nums2 = n - 1;
        while (idx_nums1 >= 0 && idx_nums2 >= 0) {
            nums1[idx_nums1] < nums2[idx_nums2] ? nums1[idx--] = nums2[idx_nums2--] : nums1[idx--] = nums1[idx_nums1--];
        }

        while (idx_nums2 >= 0) {
            nums1[idx--] = nums2[idx_nums2--];
        }
    }
};
//*/