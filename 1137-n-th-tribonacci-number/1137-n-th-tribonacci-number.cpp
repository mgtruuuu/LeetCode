class Solution {
  public:
    int tribonacci(int n)
    {
        int parts[3] = { 0, 1, 1 };

        switch (n) {
        case 0:
            return parts[0];
        case 1:
            return parts[1];
        case 2:
            return parts[1];
        default:

            for (auto idx = 3; idx <= n - 1; ++idx) {
                parts[idx % 3] = parts[0] + parts[1] + parts[2];
            }

            return parts[0] + parts[1] + parts[2];
        }
    }
};