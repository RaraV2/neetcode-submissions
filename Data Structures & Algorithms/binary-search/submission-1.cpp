class Solution {
public:
    int BS(vector<int>& nums,int s,int e,int target)
        {
            if(s>e) return -1;

            int m = (s+e)/2;
            if(target < nums[m]) { return BS(nums,s,m-1,target);}
            else if(target > nums[m]) { return BS(nums,m+1,e,target);}
            return m;
            
            
    }

    int search(vector<int>& nums, int target)
    {
        return BS(nums,0,nums.size()-1,target);
    }

};
