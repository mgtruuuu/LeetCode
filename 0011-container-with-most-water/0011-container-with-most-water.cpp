class Solution {
  public:
    int maxArea(std::vector<int>& height)
    {
        int maxarea = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int width = right - left;
            maxarea = std::max(maxarea, std::min(height[left], height[right]) * width);
            if (height[left] <= height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return maxarea;
    }
};
