class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty()) return 0;

        set<int> k(nums.begin(), nums.end());

        int res = 1;
        int temp_res = 1;

        auto it = k.begin();
        auto next_it = it;
        ++next_it;

        while (next_it != k.end()) {
            if (*next_it == *it + 1) {
                temp_res++;
            } else {
                temp_res = 1;
            }

            res = max(res, temp_res);

            ++it;
            ++next_it;
        }

        return res;
    }
};