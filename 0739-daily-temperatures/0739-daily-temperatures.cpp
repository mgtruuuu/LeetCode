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