class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        std::vector<std::string> res;

        if (nums.empty() == true) {
            return res;
        }

        auto interval_first = *nums.begin();
        auto interval_last = *nums.begin();

        for (std::size_t idx = 1; idx != nums.size(); ++idx) {
            if (interval_last + 1 == nums[idx]) {
                ++interval_last;
            }
            else {
                std::string interval;
                interval += std::to_string(interval_first);
                if (interval_first != interval_last) {
                    interval += "->";
                    interval += std::to_string(interval_last);
                }
                res.push_back(interval);

                interval_first = nums[idx];
                interval_last = nums[idx];
            }
        }

        {
            std::string interval;
            interval += std::to_string(interval_first);
            if (interval_first != interval_last) {
                interval += "->";
                interval += std::to_string(interval_last);
            }
            res.push_back(interval);
        }

        return res;
    }
};