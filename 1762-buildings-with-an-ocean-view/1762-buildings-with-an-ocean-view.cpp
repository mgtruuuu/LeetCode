///*
// Approach 1: Linear Iteration
class Solution {
  public:
    vector<int> findBuildings(vector<int>& heights)
    {
        std::stack<int> s;
        
        auto idx = static_cast<int>(heights.size());
        s.push(--idx);
        for (; idx-- != 0;) {

            if (heights[s.top()] < heights[idx]) {
                s.push(idx);
            }
        }

        std::vector<int> res;
        res.reserve(s.size());

        while (s.empty() == false) {

            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};
//*/


/*
// Approach 2: Monotonic Stack
class Solution {
  public:
    vector<int> findBuildings(vector<int>& heights)
    {
        std::stack<int> s;
        for (auto idx = 0; idx != static_cast<int>(heights.size()); ++idx) {

            while (s.empty() == false && heights[s.top()] <= heights[idx]) {
                s.pop();
            }
            
            s.push(idx);
        }

        std::vector<int> res(s.size());
        auto idx = s.size();
        while (idx-- != 0) {

            res[idx] = s.top();
            s.pop();
        }

        return res;
    }
};
*/