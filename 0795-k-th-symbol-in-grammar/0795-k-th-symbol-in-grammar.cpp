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