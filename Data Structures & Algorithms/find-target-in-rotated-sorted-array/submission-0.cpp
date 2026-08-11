class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int index{-1}, l, r, mid;
        l = 0;
        r = nums.size() - 1;

        while (l <= r) {
            mid = l + (r - l) / 2;
            
            if (nums[mid] == target) {
                return mid; 
            }

            if (nums[l] <= nums[r]) {
                // array is sorted, we do binary search
                if (target > nums[mid]) {
                    l = mid + 1;
                } else{
                    r = mid - 1;
                }
            }
            else if (nums[l] <= nums[mid]) {
                // left side is sorted
                if (target >= nums[l] && target < nums[mid]) {
                    // means inside left half
                    r = mid - 1;
                } else
                    l = mid + 1;
            } else {
                // right half is sorted
                 if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
