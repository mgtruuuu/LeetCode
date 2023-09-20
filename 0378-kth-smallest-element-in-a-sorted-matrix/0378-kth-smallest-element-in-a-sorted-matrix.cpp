class Solution {
  private:
    struct HeapNode {

        int value, r, c;

        HeapNode() = default;
        HeapNode(const int value, const int r, const int c) : value{ value }, r{ r }, c{ c }
        {
        }

        friend bool operator>(const HeapNode& c1, const HeapNode& c2)
        {
            return (c1.value > c2.value);
        }
    };

  public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        const auto len_row = static_cast<int>(matrix.size());
        const auto len_col = static_cast<int>(matrix.front().size());

        const auto comp = [](const HeapNode& a, const HeapNode& b) { return (a.value > b.value); };

        std::priority_queue<HeapNode, std::vector<HeapNode>, std::greater<HeapNode>> pq;
        const auto len_pq = std::min(len_row, k);

        for (auto r = 0; r != len_pq; ++r) {
            pq.emplace(matrix[r].front(), r, 0);
        }

        --k;
        HeapNode smallest;
        while (k-- != 0) {

            smallest = pq.top();

            pq.pop();

            if (smallest.c != len_col - 1) {
                pq.emplace(matrix[smallest.r][smallest.c + 1], smallest.r, smallest.c + 1);
            }
        }

        return pq.top().value;
    }
};