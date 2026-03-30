class Solution {
public:
    int search(vector<int>& nums, int target) {
       return BS(nums,0,nums.size()-1,target);
    }
    int BS(vector<int>& nums,int s,int e,int target)
    {
        while(s<=e)
        {
            int m = (s+e)/2;
            if(target == nums[m]) { return m; }
            else if(target < nums[m]) { e = m-1; }
            else if(target > nums[m]) { s = m+1; }
        }
        return -1;
    }    
};
