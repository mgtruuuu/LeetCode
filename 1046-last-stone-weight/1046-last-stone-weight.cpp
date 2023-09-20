class Solution {
  public:
    int lastStoneWeight(vector<int>& stones)
    {
        std::priority_queue<int> pq;

        for (const auto stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > std::size_t(1)) {

            const auto first = pq.top();
            pq.pop();
            const auto second = pq.top();
            pq.pop();

            if (first != second) {
                pq.push(first - second);
            }
        }

        if (pq.empty() == true) {
            return 0;
        }
        else {
            return pq.top();
        }
    }
};