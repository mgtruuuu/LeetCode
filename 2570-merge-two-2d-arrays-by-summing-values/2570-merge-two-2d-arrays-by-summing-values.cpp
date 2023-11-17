class Solution {
  public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2)
    {
        auto merged = std::vector<std::vector<int>>();
        merged.reserve(nums1.size() + nums2.size());

        std::size_t idx_nums1 = 0, idx_nums2 = 0;
        while (idx_nums1 != nums1.size() && idx_nums2 != nums2.size()) {

            if (nums1[idx_nums1].front() < nums2[idx_nums2].front()) {
                merged.push_back({ nums1[idx_nums1].front(), nums1[idx_nums1++].back() });
            }
            else if (nums1[idx_nums1].front() > nums2[idx_nums2].front()) {
                merged.push_back({ nums2[idx_nums2].front(), nums2[idx_nums2++].back() });
            }
            else {
                merged.push_back({ nums1[idx_nums1].front(), nums1[idx_nums1++].back() + nums2[idx_nums2++].back() });
            }
        }

        while (idx_nums1 != nums1.size()) {
            merged.push_back({ nums1[idx_nums1].front(), nums1[idx_nums1++].back() });
        }

        while (idx_nums2 != nums2.size()) {
            merged.push_back({ nums2[idx_nums2].front(), nums2[idx_nums2++].back() });
        }

        merged.shrink_to_fit();
        return merged;
    }
};
