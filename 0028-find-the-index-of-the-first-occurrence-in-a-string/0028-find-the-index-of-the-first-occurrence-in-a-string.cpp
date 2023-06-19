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