class Solution {
  public:
    int maximumPopulation(vector<vector<int>>& logs)
    {
        std::vector<int> populations(2050 - 1950, 0);
        
        for (const auto& log : logs) {
            for (auto year = log.front(); year != log.back(); ++year) {
                ++populations[year - 1950];
            }
        }
        
        auto max_population = std::numeric_limits<int>::min();
        int max_year;
        
        for (auto idx = 0; idx != static_cast<int>(populations.size()); ++idx) {
            if (max_population < populations[idx]) {
                max_population = populations[idx];
                max_year = idx + 1950;
            }
        }
        
        return max_year;
    }
};