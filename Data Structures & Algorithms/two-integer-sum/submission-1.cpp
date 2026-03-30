class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int pos{0};
        unordered_map<int,int> m;
        m.reserve(nums.size());
        for(auto x: nums){   
            int key = target-x;                   
            if(m.count(key)) return {m[key],pos};
            m.emplace(x,pos);
            pos++;
        } 
    }
};