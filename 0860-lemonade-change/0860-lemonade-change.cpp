class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int num_changes[2] = {0, 0};
        
        for (const auto& bill : bills) {
            
            switch (bill) {
                    
            case 10:
                if (num_changes[0]-- == 0) {
                    return false;
                }
                    
                ++num_changes[1];
                    
                break;

            case 20:
                if (num_changes[0] != 0 && num_changes[1] != 0) {
                    --num_changes[0];
                    --num_changes[1];                    
                }
                else if (num_changes[0] >= 3) {
                    num_changes[0] -= 3;
                }
                else {
                    return false;                    
                }
                    
                break;

            default:
                ++num_changes[0];
                break;
            }
        }
        
        return true;
    }
};