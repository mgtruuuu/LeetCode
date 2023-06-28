class Solution {
  public:
    int process(int n)
    {
        auto sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        return sum;
    }
    bool isHappy(int n)
    {
        auto fast = n;
        auto slow = n;

        while (true) {

            fast = process(process(fast));
            slow = process(slow);

            if (fast == slow) {
                break;
            }
        }

        if (fast == 1) {
            return true;
        }
        else {
            return false;
        }
    }
};




// // class Solution {
// //   public:
// //     bool isHappy(int n)
// //     {
// //         std::unordered_set<int> nums;
// //         nums.insert(n);

// //         while (true) {

// //             auto sum = 0;
// //             while (n != 0) {
// //                 sum += (n % 10) * (n % 10);
// //                 n /= 10;
// //             }

// //             n = sum;
// //             if (nums.find(n) != nums.end()) {
// //                 break;
// //             }
// //             else {
// //                 nums.insert(n);
// //             }
// //         }

// //         if (n == 1) {
// //             return true;
// //         }
// //         else {
// //             return false;
// //         }
// //     }
// // };