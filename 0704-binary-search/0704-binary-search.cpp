class Solution {
public:
    
    int search(vector<int>& nums, int target) {
       
        auto low = 0;
        auto high = static_cast<int>(nums.size()) - 1;
        
        while (low <= high) {
            const auto mid = (low + high) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};