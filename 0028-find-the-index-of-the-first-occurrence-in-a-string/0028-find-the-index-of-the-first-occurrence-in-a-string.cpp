
// Solution 1 : KMP

std::size_t KMPSearch(const std::string& pat, const std::string& txt);
std::vector<int> computeLPSArray(const std::string& pat);

class Solution {
  public:
    int strStr(string haystack, string needle)
    {
        const auto idx = KMPSearch(needle, haystack);

        if (idx != haystack.size()) {
            return static_cast<int>(idx);
        }
        else {
            return -1;
        }
    }
};

std::vector<int> computeLPSArray(const std::string& pat)
{
    auto lps = std::vector<int>(pat.size());
    lps[0] = 0; // lps[0] is always 0

    // length of the previous longest prefix suffix
    auto len = std::size_t(0);

    // the loop calculates lps[i] for i = 1 to M-1
    auto i = std::size_t(1);
    while (i != pat.size()) {
        if (pat[i] == pat[len]) {
            ++len;
            lps[i] = len;
            ++i;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                ++i;
            }
        }
    }

    return lps;
}

std::size_t KMPSearch(const std::string& pat, const std::string& txt)
{
    const auto len_pat = pat.size();
    const auto len_txt = txt.size();

    // Create lps[] that will hold the longest prefix suffix values for pattern
    const auto lps = computeLPSArray(pat);

    auto idx_txt = std::size_t(0);
    auto idx_pat = std::size_t(0);
    while ((len_txt - idx_txt) >= (len_pat - idx_pat)) {
        if (pat[idx_pat] == txt[idx_txt]) {
            ++idx_pat;
            ++idx_txt;
        }

        if (idx_pat == len_pat) {
            // printf("Found pattern at index %d\n", idx_txt - idx_pat);
            // idx_pat = lps[idx_pat - 1];

            return idx_txt - idx_pat;
        }

        // mismatch after j matches
        else if (idx_txt < len_txt && pat[idx_pat] != txt[idx_txt]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (idx_pat != 0) {
                idx_pat = lps[idx_pat - 1];
            }
            else {
                ++idx_txt;
            }
        }
    }

    return len_txt;
}




// Solution 2 : Sliding window
// // class Solution {
// //   public:
// //     int strStr(string haystack, string needle)
// //     {
// //         if (haystack.size() < needle.size()) {
// //             return -1;
// //         }
        
// //         const auto p = 113;
// //         const auto mod = 1'000'000'007;
// //         const auto c1 = pow(p, mod - 2, mod);
// //         const auto c2 = pow(p, static_cast<int>(needle.size()) - 1, mod);
// //         std::hash<char> hash_char;

// //         auto window_needle = size_t(0);
// //         for (auto idx = std::size_t(0); idx != needle.size(); ++idx) {
// //             window_needle *= c1;
// //             window_needle %= mod;
// //             window_needle += (c2 * (hash_char(needle[idx]) % mod));
// //             window_needle %= mod;
// //         }

// //         auto window_haystack = size_t(0);
// //         for (auto idx = std::size_t(0); idx != needle.size(); ++idx) {
// //             window_haystack *= c1;
// //             window_haystack %= mod;
// //             window_haystack += (c2 * (hash_char(haystack[idx]) % mod));
// //             window_haystack %= mod;
// //         }

// //         if (window_haystack == window_needle) {
// //             return 0;
// //         }

// //         for (auto idx = needle.size(); idx != haystack.size(); ++idx) {

// //             window_haystack -= hash_char(haystack[idx - needle.size()]);
// //             window_haystack %= mod;
// //             window_haystack *= c1;
// //             window_haystack %= mod;
// //             window_haystack += (c2 * (hash_char(haystack[idx]) % mod));
// //             window_haystack %= mod;

// //             if (window_haystack == window_needle) {
// //                 return (idx + 1 - static_cast<int>(needle.size()));
// //             }
// //         }

// //         return -1;
// //     }
    
// //     int pow(int x, int y, const int mod)
// //     {
// //         auto res = 1;

// //         // Check till the number becomes zero
// //         while (y > 0) {

// //             // If y is odd, multiply x with result
// //             if (y & 1) {
// //                 res = (res * std::size_t(x)) % mod;
// //             }

// //             y >>= 1; // y = y/2

// //             x = (std::size_t(x) * x) % mod; // Change x to x^2
// //         }

// //         return static_cast<int>(res);
// //     }
// // };