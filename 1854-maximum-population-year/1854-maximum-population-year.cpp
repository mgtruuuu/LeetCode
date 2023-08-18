class Solution {
  public:
    int maximumPopulation(vector<vector<int>>& logs)
    {
        std::array<int, 2050 - 1950 + 1> differences{};
        
        for (const auto& log : logs) {
            
            differences[log.front() - 1950] += 1;
            differences[log.back() - 1950] -= 1;
        }
        
        auto sum = 0;
        auto max_population = 0;
        auto max_year = 0;
        
        for (auto idx = 0; idx != 2050 - 1950 + 1; ++idx) {
            
            sum += differences[idx];
            
            if (max_population < sum) {
                max_population = sum;
                max_year = idx + 1950;
            }
        }
        
        return max_year;
    }
};