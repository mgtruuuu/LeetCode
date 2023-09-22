///*
// Approach 1: Sort
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        std::vector<std::vector<int>> points_sorted = points;
        std::nth_element(points_sorted.begin(), points_sorted.begin() + k, points_sorted.end(),
                         [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
                             return (lhs.front() * lhs.front() + lhs.back() * lhs.back()) <
                                    (rhs.front() * rhs.front() + rhs.back() * rhs.back());
                         });

        return std::vector<std::vector<int>>{ points_sorted.begin(), points_sorted.begin() + k };
    }
};
//*/



/*
// HEAP !!!!
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        const auto comp = [&points](int lhs, int rhs) {
            return (points[lhs].front() * points[lhs].front() + points[lhs].back() * points[lhs].back()) <
                   (points[rhs].front() * points[rhs].front() + points[rhs].back() * points[rhs].back());
        };

        using Comparator = std::function<bool(int, int)>;
        std::priority_queue<int, std::vector<int>, Comparator> pq(comp);

        for (auto idx = 0; idx != static_cast<int>(points.size()); ++idx) {

            pq.push(idx);

            if (pq.size() > std::size_t(k)) {
                pq.pop();
            }
        }

        std::vector<std::vector<int>> res;
        res.reserve(k);
        
        while (pq.empty() == false) {

            res.push_back(points[pq.top()]);
            pq.pop();
        }
        
        return res;
    }
};
*/
