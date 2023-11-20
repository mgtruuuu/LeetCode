/*
// Approach 1: Two pointers
class Solution {
  public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration)
    {
        std::sort(slots1.begin(), slots1.end());
        std::sort(slots2.begin(), slots2.end());

        std::size_t idx_slots1 = 0, idx_slots2 = 0;
        while (idx_slots1 != slots1.size() && idx_slots2 != slots2.size()) {

            const auto slot1_end = slots1[idx_slots1].back();
            const auto slot2_end = slots2[idx_slots2].back();
            const auto max_start = std::max(slots1[idx_slots1].front(), slots2[idx_slots2].front());

            if (std::min(slot1_end, slot2_end) - max_start >= duration) {
                return { max_start, max_start + duration };
            }

            if (slot1_end <= slot2_end) {
                ++idx_slots1;
            }

            if (slot1_end >= slot2_end) {
                ++idx_slots2;
            }
        }

        return {};
    }
};
*/


class Solution {
  public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration)
    {
        using MyPair = std::vector<int>;

        struct Comp {

            bool operator()(const MyPair& lhs, const MyPair& rhs) const
            {
                return lhs.front() > rhs.front();
            }
        };

        std::priority_queue<MyPair, std::vector<MyPair>, Comp> pq;
        for (const auto& slot1 : slots1) {
            if (slot1.back() >= slot1.front() + duration) {
                pq.push(slot1);
            }
        }

        for (const auto& slot2 : slots2) {
            if (slot2.back() >= slot2.front() + duration) {
                pq.push(slot2);
            }
        }

        while (pq.size() > 1) {

            const auto temp = pq.top();
            pq.pop();

            if (temp.back() >= pq.top().front() + duration) {
                return { pq.top().front(), pq.top().front() + duration };
            }
        }

        return {};
    }
};