class Solution {
  public:
    int findTheWinner(int n, int k)
    {
        std::queue<int> q;

        for (auto i = 1; i <= n; ++i) {
            q.push(i);
        }

        while (q.size() >= 2) {

            for (auto j = k - 1; j-- != 0;) {

                auto temp = q.front();

                q.pop();
                q.push(temp);
            }

            q.pop();
        }

        return q.front();
    }
};