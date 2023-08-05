class Solution {
  public:
    int addDigits(int num)
    {        
        if (num == 0) {
            return 0;
        }
        
        const auto res = num % 9;
        if (res == 0) {
            return 9;
        }
        else {
            return res;
        }
    }
};

/*
class Solution {
  public:
    int addDigits(int num)
    {        
        auto res = num;
        
        while (res > 9) {
            
            num = res;
            res = 0;
            while (num != 0) {
                res += (num % 10);
                num /= 10;
            }
        }
        
        return res;
    }
};
*/