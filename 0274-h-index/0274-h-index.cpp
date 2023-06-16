class Solution {
  public:
    int hIndex(vector<int>& citations)
    {
        auto len_citations = citations.size();
        auto sum = 0;
        auto counts = std::vector<int>(1001, 0);
        for (auto idx = std::size_t(0); idx != len_citations; ++idx) {
            sum += citations[idx];
            ++counts[citations[idx]];
        }

        auto max_candidate = std::min(static_cast<int>(sqrt(static_cast<double>(sum))), 999);

        auto temp = std::accumulate(counts.begin() + max_candidate, counts.end(), 0);

        while (temp < max_candidate) {
            temp += counts[--max_candidate];
        }

        return max_candidate;
    }
};