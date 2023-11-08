///*
// Approach 1: Recursion, In-Place, O(N) Space
class Solution {
  private:
    void reverseStringHelper(std::vector<char>& s, const std::size_t idx)
    {
        if (idx == s.size() / 2) {
            return;
        }

        std::swap(s[idx], s[s.size() - 1 - idx]);
        reverseStringHelper(s, idx + 1);
    }

  public:
    void reverseString(vector<char>& s)
    {
        reverseStringHelper(s, 0);
    }
};
//*/



/*
// Approach 2: Two Pointers, Iteration, O(1)\mathcal{O}(1)O(1) Space
class Solution {
  public:
    void reverseString(vector<char>& s)
    {
        auto len_s = static_cast<int>(s.size());

        for (auto idx = 0; idx != len_s / 2; ++idx) {
            std::swap(s[idx], s[len_s - 1 - idx]);
        }
    }
};
*/