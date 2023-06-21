class Solution {
  public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() < needle.size()) {
            return -1;
        }
        
        const auto p = 113;
        const auto mod = 1'000'000'007;
        const auto c1 = pow(p, mod - 2, mod);
        const auto c2 = pow(p, static_cast<int>(needle.size()) - 1, mod);
        std::hash<char> hash_char;

        auto window_needle = size_t(0);
        for (auto idx = std::size_t(0); idx != needle.size(); ++idx) {
            window_needle *= c1;
            window_needle %= mod;
            window_needle += (c2 * (hash_char(needle[idx]) % mod));
            window_needle %= mod;
        }

        auto window_haystack = size_t(0);
        for (auto idx = std::size_t(0); idx != needle.size(); ++idx) {
            window_haystack *= c1;
            window_haystack %= mod;
            window_haystack += (c2 * (hash_char(haystack[idx]) % mod));
            window_haystack %= mod;
        }

        if (window_haystack == window_needle) {
            return 0;
        }

        for (auto idx = needle.size(); idx != haystack.size(); ++idx) {

            window_haystack -= hash_char(haystack[idx - needle.size()]);
            window_haystack %= mod;
            window_haystack *= c1;
            window_haystack %= mod;
            window_haystack += (c2 * (hash_char(haystack[idx]) % mod));
            window_haystack %= mod;

            if (window_haystack == window_needle) {
                return (idx + 1 - static_cast<int>(needle.size()));
            }
        }

        return -1;
    }
    
    int pow(int x, int y, const int mod)
    {
        auto res = 1;

        // Check till the number becomes zero
        while (y > 0) {

            // If y is odd, multiply x with result
            if (y & 1) {
                res = (res * std::size_t(x)) % mod;
            }

            y >>= 1; // y = y/2

            x = (std::size_t(x) * x) % mod; // Change x to x^2
        }

        return static_cast<int>(res);
    }
};