class Solution {
  public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
    {
        const auto left_bottom_max_x = std::max(rec1[0], rec2[0]);
        const auto left_bottom_max_y = std::max(rec1[1], rec2[1]);
        const auto right_up_min_x = std::min(rec1[2], rec2[2]);
        const auto right_up_min_y = std::min(rec1[3], rec2[3]);

        return left_bottom_max_x < right_up_min_x && left_bottom_max_y < right_up_min_y ? true : false;

        if ((rec1[0] < rec2[0] && rec2[0] < rec1[2] && rec1[1] < rec2[1] && rec2[1] < rec1[3]) ||
            (rec2[0] < rec1[0] && rec1[0] < rec2[2] && rec2[1] < rec1[1] && rec1[1] < rec2[3])) {
            return true;
        }
        return false;
    }
};