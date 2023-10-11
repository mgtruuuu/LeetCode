class Solution {
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        const auto len = static_cast<int>(gas.size());

        auto sum_all = 0;
        auto sum_part = 0;
        auto idx_part_start = 0;
        for (auto idx = 0; idx != len; ++idx) {

            sum_part += gas[idx] - cost[idx];
            sum_all += gas[idx] - cost[idx];
            
            if (sum_part < 0) {

                sum_part = 0;
                idx_part_start = idx + 1;
            }
        }

        return sum_all < 0 ? -1 : idx_part_start;
    }
};