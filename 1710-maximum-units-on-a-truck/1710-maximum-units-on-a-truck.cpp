///*
// Approach 1: Using Array Sort
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
//*/


/*
// Approach 2: Using Priority Queue
class Solution {
  private:
    struct Comparator {
        bool operator()(const std::vector<int>& p1, const std::vector<int>& p2)
        {
            return p1[1] < p2[1];
        }
    };

  public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Comparator> pq;
        for (const auto& box_type : boxTypes) {
            pq.push(box_type);
        }

        auto num_unit = 0;

        while (pq.empty() == false) {

            const auto box_type = pq.top();
            pq.pop();

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
*/