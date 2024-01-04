class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        vector<int> nearestRightCandle(s.length(), 0);
        vector<int> nearestLeftCandle(s.length(), 0);
        vector<int> cumulativePlates(s.length(), 0);

    // index    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    // string   * | * * * * * * | | *  |  |  *  *  |
    // right    1 1 9 9 9 9 9 9 9 9 11 12 12 15 15 15
    // left     0 1 1 1 1 1 1 1 8 8 8  11 11 11 11 15

        int sum = 0;
        int leftCandle = 0;
        bool isPreviousCandle;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {
                sum++;
                nearestLeftCandle[i] = leftCandle;
                isPreviousCandle = false;
            }
            else {
                if (isPreviousCandle) {
                    nearestLeftCandle[i] = leftCandle;
                }
                else {
                    nearestLeftCandle[i] = i;
                    leftCandle = i;
                }
            }

            cumulativePlates[i] = sum;
        }

        int rightCandle = s.length()-1;
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] == '*') {
                nearestRightCandle[i] = rightCandle;
                isPreviousCandle = false;
            }
            else {
                if (isPreviousCandle) {
                    nearestRightCandle[i] = rightCandle;
                }
                else {
                    nearestRightCandle[i] = i;
                    rightCandle = i;
                }
            }
        }


        int left, right;
        for (int i = 0; i < queries.size(); i++) {
            left = queries[i][0];
            right = queries[i][1];
            right = nearestLeftCandle[right];
            left = nearestRightCandle[left];
            if (right > left) {
                ans[i] = cumulativePlates[right] - cumulativePlates[left];
            }
        }

        return ans;
    }

};