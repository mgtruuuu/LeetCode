class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0) {
            return 0;
        }

        const auto none = 10001;

        const auto min_coin = *std::min_element(coins.begin(), coins.end());

        if (min_coin > amount)
        {
            return -1;
        }
        
        
        std::vector<int> list_res(amount + 1, none);
        list_res[0] = 0;
        list_res[min_coin] = 1;
        

        for (auto idx = min_coin + 1; idx != amount + 1; ++idx) {
            auto min_pre = none;

            for (const auto coin : coins) {

                if (idx - coin < 0) {
                    continue;
                }
                
                min_pre = std::min(min_pre, list_res[idx - coin]);
            }

            if (min_pre != none) {
                list_res[idx] = min_pre + 1;
            }
        }

        auto res = list_res.back();

        if (res == none) {
            res = -1;
        }

        return res;
    }
};