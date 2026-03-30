class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        multiset<int> s(nums.begin(),nums.end());
        for(auto x: s)
        {
            if (s.count(x) > 1) return true;
        }
            return false;
    }
};