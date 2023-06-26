class Solution {
public:
    int countOdds(int low, int high) {
        if (low & 1) {
            return (high + 2 - low) / 2;
        }
        else {
            return (high + 1 - low) / 2;
        }
    }
};