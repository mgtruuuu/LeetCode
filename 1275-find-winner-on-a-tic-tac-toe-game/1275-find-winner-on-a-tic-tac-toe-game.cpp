class Solution {
  public:
    struct Score {
        int cols[3] = { 0, 0, 0 };
        int rows[3] = { 0, 0, 0 };
        int d_048 = 0;
        int d_246 = 0;
    };

    string tictactoe(vector<vector<int>>& moves)
    {
        Score scores[2];

        for (auto idx = std::size_t(0); idx != moves.size(); ++idx) {

            const auto& move = moves[idx];

            const auto idx_score = idx & 1;

            scores[idx_score].rows[move.front()] += 1;
            scores[idx_score].cols[move.back()] += 1;
            if (move.front() == move.back()) {
                scores[idx_score].d_048 += 1;
            }
            if (move.front() + move.back() == 2) {
                scores[idx_score].d_246 += 1;
            }

            for (const auto& row : scores[idx_score].rows) {
                if (row == 3) {
                    return (idx_score == 0 ? "A" : "B");
                }
            }

            for (const auto& col : scores[idx_score].cols) {
                if (col == 3) {
                    return (idx_score == 0 ? "A" : "B");
                }
            }

            if (scores[idx_score].d_048 == 3 || scores[idx_score].d_246 == 3) {
                return (idx_score == 0 ? "A" : "B");
            }
        }

        if (moves.size() == 9) {
            return "Draw";
        }
        else {
            return "Pending";
        }
    }
};