class Solution {
  public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        std::sort(boxTypes.begin(), boxTypes.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) { return a.back() > b.back(); });

        auto num_unit = 0;
        auto count = 0;
        for (const auto& box_type : boxTypes) {
            if (box_type.front() >= truckSize - count) {
                num_unit += (truckSize - count) * box_type.back();

                break;
            }

            num_unit += box_type.front() * box_type.back();
            count += box_type.front();
        }

        return num_unit;
    }
};