// Approach 2: Bitwise operators : Turn off the Rightmost 1-bit
class Solution
{
  public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0) {
            return false;
        }
        
        return ((n & (n - 1)) == 0);
    }
};



/*
// Approach 1: Bitwise Operators : Get the Rightmost 1-bit
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
*/