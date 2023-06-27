class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int num_changes[3] = {0, 0, 0};
        
        for (const auto& bill : bills) {
            
            switch (bill) {
                    
            case 10:
                if (num_changes[0]-- == 0) {
                    return false;
                }
                    
                ++num_changes[1];
                    
                break;

            case 20:
                if (num_changes[0] == 0 || 5 * num_changes[0] + 10 * num_changes[1] < 15) {
                    return false;
                }
                    
                if (num_changes[0] == 0) {
                    num_changes[0] -= 3;
                }
                else {
                    --num_changes[0];
                    --num_changes[1];
                }
                    
                ++num_changes[2];
                    
                break;

            default:
                ++num_changes[0];
                break;
            }
        }
        
        return true;
    }
};