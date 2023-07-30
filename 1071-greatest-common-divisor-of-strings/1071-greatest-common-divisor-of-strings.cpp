class Solution {
  public:
    string gcdOfStrings(string str1, string str2)
    {
        
        // Check if they have non-zero GCD string.
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Get the GCD of the two lengths.
        const auto gcd_length = std::gcd(str1.size(), str2.size());
        return str1.substr(0, gcd_length);
    }
};