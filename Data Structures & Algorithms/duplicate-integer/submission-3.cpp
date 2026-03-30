class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        unordered_set<int> s;
        for(auto x: nums) //iterate each element
        {
            if (s.count(x)) return true; //countn could be 0/1, if 1 then returns true
            s.insert(x);
        }
            return false;
    }
};