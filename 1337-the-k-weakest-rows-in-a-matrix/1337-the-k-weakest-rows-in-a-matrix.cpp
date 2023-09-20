/*
class Solution {
  private:
    int getNumSoldiers(const std::vector<int>& row)
    {
        auto idx_front = 0;
        auto idx_back = static_cast<int>(row.size()) - 1;

        while (idx_front <= idx_back) {

            const auto idx_middle = (idx_front + idx_back) / 2;

            if (row[idx_middle] == 1) {
                idx_front = idx_middle + 1;
            }
            else {
                idx_back = idx_middle - 1;
            }
        }

        return idx_front;
    }

  public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        std::priority_queue<std::pair<int, int>> pq;

        for (auto row = 0; row != static_cast<int>(mat.size()); ++row) {

            pq.emplace(getNumSoldiers(mat[row]), row);

            if (std::size_t(k) < pq.size()) {
                pq.pop();
            }
        }

        std::vector<int> res(k);
        auto idx = k;
        while (pq.empty() == false) {

            res[--k] = pq.top().second;
            pq.pop();
        }

        return res;
    }
};
*/



class Solution {
  public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        std::vector<int> res;
        res.reserve(k);

        for (auto col = std::size_t(0); col != mat.front().size(); ++col) {
            for (auto row = std::size_t(0); row != mat.size(); ++row) {

                if (mat[row][col] == 1) {
                    continue;
                }

                if (col != 0 && mat[row][col - 1] == 0) {
                    continue;
                }

                res.push_back(row);

                if (res.size() == k) {
                    return res;
                }
            }
        }
        
        for (auto row = std::size_t(0); row != mat.size(); ++row) {

            if (mat[row][mat.front().size() - 1] == 0) {
                continue;
            }

            res.push_back(row);

            if (res.size() == k) {
                return res;
            }
        }

        return res;
    }
};