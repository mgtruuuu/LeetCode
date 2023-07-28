class Solution {
  public:
    vector<string> fizzBuzz(int n)
    {
        std::vector<std::string> res;
        
        for (auto i = 1; i <= n; ++i) {
            
            const bool divisible_by_3 = (i % 3 == 0);
            const bool divisible_by_5 = (i % 5 == 0);
            
            if (divisible_by_3 && divisible_by_5) {
                res.push_back("FizzBuzz");
            }
            else if (divisible_by_3) {
                res.push_back("Fizz");
            }
            else if (divisible_by_5) {
                res.push_back("Buzz");
            }
            else {
                res.push_back(std::to_string(i));
            }            
        }
                      
        return res;
    }
};