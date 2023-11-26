/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
  public:
    int guessNumber(int n)
    {
        int64_t min = 1;
        int64_t max = n;
        int64_t middle = (min + max) / 2;
        int64_t det = guess(middle);
        while (min <= max) {

            if (det < 0) {
                max = middle - 1;
            }
            else if (det > 0) {
                min = middle + 1;
            }
            else {
                return middle;
            }

            middle = (min + max) / 2;
            det = guess(middle);
        }

        return -1;
    }
};