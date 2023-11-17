class Solution {
  public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration)
    {
        std::sort(slots1.begin(), slots1.end());
        std::sort(slots2.begin(), slots2.end());
        
        std::size_t idx_slots1 = 0, idx_slots2 = 0;
        while (idx_slots1 != slots1.size() && idx_slots2 != slots2.size()) {

            const auto slot1_start = slots1[idx_slots1].front();
            const auto slot1_end = slots1[idx_slots1].back();
            const auto slot2_start = slots2[idx_slots2].front();
            const auto slot2_end = slots2[idx_slots2].back();
            const auto max_start = std::max(slot1_start, slot2_start);
            const auto min_end = std::min(slot1_end, slot2_end);

            if (min_end - max_start >= duration) {
                return { max_start, max_start + duration };
            }

            if (slot1_end < slot2_end) {
                idx_slots1++;
            }
            else if (slot1_end > slot2_end) {
                idx_slots2++;
            }
            else {
                idx_slots1++;
                idx_slots2++;
            }
        }

        return {};
    }
};
