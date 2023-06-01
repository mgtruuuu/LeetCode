class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        if (nums.empty() == true) {
            return {};
        }

        std::vector<std::string> res;

        auto ptr = nums.begin() + 1;

        auto interval_first = *nums.begin();
        auto interval_last = *nums.begin();
        while (ptr != nums.end()) {

            if (interval_last + 1 == *ptr) {
                ++interval_last;
                ++ptr;
            }
            else {
                std::string interval;
                interval += std::to_string(interval_first);
                if (interval_first != interval_last) {
                    interval += "->";
                    interval += std::to_string(interval_last);
                }
                res.push_back(interval);

                interval_first = *ptr;
                interval_last = *ptr;
                ++ptr;
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