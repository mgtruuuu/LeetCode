class Solution {
  public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size()) {
            return false;
        }

        if (s == goal) {

            bool alphabets[26] = {
                false,
            };

            for (const auto ch : s) {

                const auto idx = static_cast<int>(ch) - static_cast<int>('a');
                if (alphabets[idx] == true) {
                    return true;
                }

                alphabets[idx] = true;
            }

            return false;
        }

        std::vector<int> indices;

        for (auto idx = std::size_t(0); idx != s.size(); ++idx) {
            if (s[idx] != goal[idx]) {
                indices.push_back(idx);
            }
        }

        if (indices.size() != 2) {
            return false;
        }

        if (s[indices.front()] == goal[indices.back()] && s[indices.back()] == goal[indices.front()]) {
            return true;
        }
        else {
            return false;
        }
    }
};