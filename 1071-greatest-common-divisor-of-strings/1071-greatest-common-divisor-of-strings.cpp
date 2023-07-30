class Solution {
  public:
    string gcdOfStrings(string str1, string str2)
    {
        return ((str1 + str2) == (str2 + str1)) ? 
               str1.substr(0, std::gcd(str1.size(), str2.size())) :
               std::string{};
    }
};


/*
class Solution {
  public:
    string gcdOfStrings(string str1, string str2)
    {
        
        // Check if they have non-zero GCD string.
        // If there exists chunk P containing more than one element
        // such that str1 = PP...P and str2 = PP...P,
        // then str1 + str2 = str2 + str1;
        // AND VICE VERSA !!!
        // (gcd(a, b) == gcd(a-b, b))
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Get the GCD of the two lengths.
        const auto gcd_length = std::gcd(str1.size(), str2.size());
        
        return str1.substr(0, gcd_length);
    }
};
*/