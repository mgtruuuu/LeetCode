class Solution {
  public:
    bool isHappy(int n)
    {
        std::unordered_set<int> nums;
        nums.insert(n);

        while (true) {
            std::vector<int> digits;
            while (n != 0) {
                digits.push_back(n % 10);
                n /= 10;
            }

            for (const auto& digit : digits) {
                n += digit * digit;
            }

            if (nums.find(n) != nums.end()) {
                break;
            }

            nums.insert(n);
        }

        if (n == 1) {
            return true;
        }
        else {
            return false;
        }
    }
};