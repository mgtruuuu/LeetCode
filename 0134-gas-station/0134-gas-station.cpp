class Solution {
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        const auto len = static_cast<int>(gas.size());

        auto curr_gain = 0;
        auto total_gain = 0;

        auto answer = 0;

        for (auto i = 0; i < len; ++i) {

            // gain[i] = gas[i] - cost[i]
            total_gain += gas[i] - cost[i];
            curr_gain += gas[i] - cost[i];

            // If we meet a "valley", start over from the next station
            // with 0 initial gas.
            if (curr_gain < 0) {
                answer = i + 1;
                curr_gain = 0;
            }
        }

        return (total_gain >= 0 ? answer : -1);
    }
};