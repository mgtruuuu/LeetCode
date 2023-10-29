/*
// Approach 1: Linear Iteration (본질은 Monotonic Stack)
class Solution {
  public:
    vector<int> findBuildings(vector<int>& heights)
    {
        std::vector<int> res;
        for (auto idx = 0; idx != static_cast<int>(heights.size()); ++idx) {

            while (res.empty() == false && heights[res.back()] <= heights[idx]) {
                res.pop_back();
            }

            res.push_back(idx);
        }

        return res;
    }
};
*/



///*
// Approach 2: Monotonic Stack
class Solution {
  public:
    vector<int> findBuildings(vector<int>& heights)
    {
        std::stack<int> s;
        std::vector<int> res;

        for (auto idx = static_cast<int>(heights.size()); idx-- != 0;) {

            while (s.empty() == false && heights[s.top()] < heights[idx]) {
                s.pop();
            }

            if (s.empty() == true) {
                res.push_back(idx);
            }
            
            s.push(idx);
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};
//*/


/*
// Approach 3: Monotonic Stack Space Optimization
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
*/