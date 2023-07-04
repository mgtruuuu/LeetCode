class Solution {
  public:
    string convertToBase7(int num)
    {
        std::string res;
        auto is_positive = true;
        
        if (num < 0) {
            is_positive = false;
            res.push_back('-');
            
            num = -num;
        }

        do {
            auto r = num;
            num /= 7;
            r -= 7 * num;

            res.push_back(r + static_cast<int>('0'));            
        } while (num != 0);
        
        if (is_positive == true) {
            for (auto idx = std::size_t(0); idx != res.size() / 2; ++idx) {
                std::swap(res[idx], res[res.size() - 1 - idx]);
            }
        }
        else {
            for (auto idx = std::size_t(0); idx != (res.size() - 1) / 2; ++idx) {
                std::swap(res[idx + 1], res[res.size() - 1 - idx]);
            }
        }

        return res;
    }
};