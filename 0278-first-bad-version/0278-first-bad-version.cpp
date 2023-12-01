// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion(int n)
    {
        auto idx_start = 1;
        auto idx_end = n;
        while (idx_start <= idx_end) {

            const auto idx_middle = idx_start + (idx_end - idx_start) / 2;

            const auto temp = isBadVersion(idx_middle);

            if (temp == true) {
                idx_end = idx_middle - 1;
            }
            else {
                idx_start = idx_middle + 1;
            }
        }

        return idx_start;
    }
};