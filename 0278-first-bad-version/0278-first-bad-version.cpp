// The API isBadVersion is defined for you.
// bool isBadVersion(int version);


///*
class Solution {
  public:
    int firstBadVersion(int n)
    {
        auto idx_left = 1;
        auto idx_right = n;
        while (idx_left <= idx_right) {

            const auto idx_middle = idx_left + (idx_right - idx_left) / 2;
            const auto temp = isBadVersion(idx_middle);

            if (temp == true) {
                idx_right = idx_middle - 1;
            }
            else {
                idx_left = idx_middle + 1;
            }
        }

        return idx_left;
    }
};
//*/


/*
class Solution {
  public:
    int firstBadVersion(int n)
    {
        auto idx_left = 1;
        auto idx_right = n;
        while (idx_left < idx_right) {

            const auto mid = idx_left + (idx_right - idx_left) / 2;

            if (isBadVersion(mid) == true) {
                idx_right = mid;
            }
            else {
                idx_left = mid + 1;
            }
        }

        return idx_left;
    }
};
*/

