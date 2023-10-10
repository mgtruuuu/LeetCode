class Solution {
  public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        std::sort(boxTypes.begin(), boxTypes.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) { return a.back() > b.back(); });

        auto num_unit = 0;
        for (const auto& box_type : boxTypes) {
            
            const auto box_count = std::min(box_type.front(), truckSize);
            
            num_unit += box_count * box_type.back();
            truckSize -= box_count;
            
            if (truckSize == 0) {
                return num_unit;
            };
        }

        return num_unit;
    }
};