// Approach 1: BST ??
class Solution {
  public:
    int kthGrammar(int n, int k)
    {
        auto left = 1;
        auto right = static_cast<int>(pow(2, n - 1));

        auto init = 0;
        while (--n != 0) {

            const auto middle = (left + right) / 2;

            if (k <= middle) {
                right = middle;
            }
            else {

                init = 1 - init;
                left = middle + 1;
            }
        }

        return init;
    }
};


/*
// Approach 2: Normal Recursion
class Solution {
  public:
    int kthGrammar(int n, int k)
    {
        if (n == 1) {
            return 0;
        }

        return k & 1 ? kthGrammar(n - 1, (k + 1) / 2) : 1 - kthGrammar(n - 1, (k + 1) / 2);
    }
};
*/


// others...