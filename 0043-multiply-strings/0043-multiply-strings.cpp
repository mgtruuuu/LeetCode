class Solution {
  public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        const auto len_res = num1.size() + num2.size();
        std::vector<int> res(len_res, 0);
        const auto zero_int = static_cast<int>('0');

        for (auto idx_num2 = std::size_t(0); idx_num2 != num2.size(); ++idx_num2) {
            for (auto idx_num1 = std::size_t(0); idx_num1 != num1.size(); ++idx_num1) {

                res[len_res - 1 - idx_num1 - idx_num2] += (static_cast<int>(num1[num1.size() - 1 - idx_num1]) - zero_int) *
                                                      (static_cast<int>(num2[num2.size() - 1 - idx_num2]) - zero_int);
            }
        }

        auto added = 0;
        for (auto idx_res = res.size(); idx_res-- != 0;) {

            const auto q = (res[idx_res] + added) / 10;
            res[idx_res] += added - q * 10;
            
            added = q;
        }

        std::string answer;
        answer.reserve(len_res);

        for (auto idx = std::size_t(0); idx != res.size(); ++idx) {

            if (idx == 0 && res[idx] == 0) {
                continue;
            }

            answer.push_back(static_cast<char>(res[idx] + zero_int));
        }

        answer.shrink_to_fit();
        return answer;
    }
};