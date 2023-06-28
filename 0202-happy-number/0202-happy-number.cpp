class Solution {
  public:
    bool isHappy(int n)
    {
        std::unordered_set<int> nums;
        nums.insert(n);

        while (true) {

            auto sum = 0;
            while (n != 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }

            n = sum;
            if (nums.find(n) != nums.end()) {
                break;
            }
            else {
                nums.insert(n);    
            }
        }

        if (n == 1) {
            return true;
        }
        else {
            return false;
        }
    }
};