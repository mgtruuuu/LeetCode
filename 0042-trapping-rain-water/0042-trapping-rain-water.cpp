class Solution {
  public:
    int trap(vector<int>& height)
    {
        auto amount = 0;

        std::stack<int> s;

        auto idx = std::size_t(0);
        while (idx != height.size()) {

            while (s.empty() == false && height[idx] > height[s.top()]) {

                auto top = s.top();
                s.pop();

                if (s.empty() == true) {
                    break;
                }

                auto dist = idx - s.top() - 1;
                auto height_bounded = std::min(height[idx], height[s.top()]) - height[top];
                amount += dist * height_bounded;
            }

            s.push(idx++);
        }

        return amount;
    }
};