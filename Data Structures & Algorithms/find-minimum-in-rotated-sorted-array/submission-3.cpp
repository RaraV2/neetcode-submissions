class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l{}, r{}, mid{};
        int minimum{1001};

        l = 0;
        r = (int) nums.size() - 1;
        while (l <= r) {
            mid = l + (r - l) / 2;

            minimum = min(minimum, nums[mid]);
            
            if (nums[l] <= nums[r]) {
                minimum = min(minimum, nums[l]);
                break; // no need to continue we found th mini of this seg
            }

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
