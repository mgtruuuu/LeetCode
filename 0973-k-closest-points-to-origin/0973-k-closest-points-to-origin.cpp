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