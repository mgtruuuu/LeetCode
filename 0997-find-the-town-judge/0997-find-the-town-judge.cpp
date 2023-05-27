class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        auto res = -1;

        std::vector<int> list_from(n, 0);
        std::vector<int> list_to(n, 0);

        for (const auto& p : trust)
        {
            ++list_from[p[0] - 1];
            ++list_to[p[1] - 1];
        }

        for (auto idx = 0; idx < n; ++idx)
        {
            if (list_from[idx] == 0 && list_to[idx] == n - 1)
            {
                res = idx + 1;
                break;
            }
        }

        return res;
    }
};