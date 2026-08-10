class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n{static_cast<int>(nums.size())}, l{}, r{}, mid{};
        int minimum{1001};

        l = 0;
        r = n - 1;
        while (l <= r) {
            mid = l + (r - l) / 2;

            minimum = min(minimum, nums[mid]);

            if (nums[l] <= nums[mid]) {
                // left side is sorted
                minimum = min(minimum,nums[l]);
                l = mid + 1; //search the right half
            }
            else {
                // in right hand side
                minimum = min(minimum, nums[mid]);
                r = mid - 1;
            }
        }

        return minimum;
    }
};
