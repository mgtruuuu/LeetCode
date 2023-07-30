class Solution
{
  public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0 || n == std::numeric_limits<int>::max()) {
            return false;
        }
        
        return ((n & (-n)) == n);
    }
};



/*
class Solution {
  public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0) {
            return false;
        }
        
        uint32_t unsigned_n = n;
        
        auto cnt = 0;
        
        while (n != 0) {
            if (n & 1) {
                ++cnt;
            }
            
            n >>= 1;
        }
        
        if (cnt == 1) {
            return true;
        }
        else {
            return false;
        }
    }
};
*/