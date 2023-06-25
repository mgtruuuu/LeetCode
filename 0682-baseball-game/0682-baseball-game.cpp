class Solution {
  public:
    int calPoints(vector<string>& operations)
    {
        std::vector<int> nums;
        nums.reserve(operations.size());

        for (const auto& op_str : operations) {

            switch (op_str.front()) {
            case '+':
                nums.push_back(nums[nums.size() - 1] + nums[nums.size() - 2]);
                break;

            case 'C':
                nums.resize(nums.size() - 1);
                break;

            case 'D':
                nums.push_back(2 * nums[nums.size() - 1]);
                break;
                    
            default:
                nums.push_back(std::stoi(op_str));
                break;
            }
        }

        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};