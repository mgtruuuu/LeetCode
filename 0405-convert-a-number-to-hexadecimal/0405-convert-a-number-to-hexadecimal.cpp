class Solution {
  private:
    std::string toHexHelper(unsigned int num)
    {
        std::string res;

        do {
            auto count = 4;
            auto hex = 0;
            auto mul = 1;
            do {
                if (num & 1) {
                    hex += mul;
                }

                num >>= 1;
                mul *= 2;

            } while (num != 0 && --count != 0);

            res.push_back(hex < 10 ? '0' + hex : 'a' + (hex - 10));

        } while (num != 0);

        std::reverse(res.begin(), res.end());
        return res;
    }

  public:
    string toHex(int num)
    {
        return toHexHelper(num);
    }
};