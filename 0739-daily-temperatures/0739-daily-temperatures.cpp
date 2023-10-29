/*
// Approach 1: Monotonic Stack
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        std::vector<int> res(temperatures.size());

        std::stack<int> s;
        for (auto idx = 0; idx != static_cast<int>(temperatures.size()); ++idx) {

            while (s.empty() == false && temperatures[s.top()] < temperatures[idx]) {

                res[s.top()] = idx - s.top();
                s.pop();
            }

            s.push(idx);
        }

        while (s.empty() == false) {

            res[s.top()] = 0;
            s.pop();
        }

        return res;
    }
};
*/


///*
// Approach 2: Array, Optimized Space
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        std::stack<int> s;
        for (auto idx = 0; idx != static_cast<int>(temperatures.size()); ++idx) {

            while (s.empty() == false && temperatures[s.top()] < temperatures[idx]) {

                temperatures[s.top()] = idx - s.top();
                s.pop();
            }

            s.push(idx);
        }

        while (s.empty() == false) {

            temperatures[s.top()] = 0;
            s.pop();
        }

        return temperatures;
    }
};
//*/