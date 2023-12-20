class Solution {
  public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        std::priority_queue<int> pq;
        for (const auto i : score) {
            pq.push(i);
        }

        constexpr auto n = 3 + 1;
        const char* names[n] = { " Medal", "Gold", "Silver", "Bronze" };

        std::unordered_map<int, std::string> score2rank;

        for (auto rank = 1; rank <= static_cast<int>(score.size()); ++rank) {

            if (pq.empty() == true) {
                break;
            }

            if (rank < n) {
                score2rank[pq.top()] = std::string{ names[rank] } + names[0];
            }
            else {
                score2rank[pq.top()] = std::to_string(rank);
            }

            pq.pop();
        }

        std::vector<std::string> ranks;
        ranks.reserve(score.size());
        for (const auto i : score) {
            ranks.push_back(score2rank[i]);
        }
        return ranks;
    }
};