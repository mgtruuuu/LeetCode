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
        auto left = 1;
        auto right = n;

        auto middle = 0;
        auto det = 0;
        while (left <= right) {

            middle = left + (right - left) / 2;
            det = guess(middle);

            if (det < 0) {
                right = middle - 1;
            }
            else if (det > 0) {
                left = middle + 1;
            }
            else {
                return middle;
            }
        }

        return -1;
    }
};