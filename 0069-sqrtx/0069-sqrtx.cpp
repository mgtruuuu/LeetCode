class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
            
        auto first = 1;
        auto last = x/2;
        while (first <= last) {
            auto mid = (first + last) / 2;
            
            if (mid  == x / mid) {
                return mid;
            }
            else if (mid > x / mid) {
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }
        
        return last;
    }
};