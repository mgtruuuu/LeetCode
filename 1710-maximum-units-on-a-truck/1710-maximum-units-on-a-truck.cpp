class Solution {
  public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        std::sort(boxTypes.begin(), boxTypes.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) { return a.back() > b.back(); });

        auto num_unit = 0;
        for (const auto& box_type : boxTypes) {
            
            auto num_box = box_type.front();
            while (num_box-- != 0) {
                
                num_unit += box_type.back();
                if (--truckSize == 0) {
                    return num_unit;
                };
            }
        }

        return num_unit;
    }
};