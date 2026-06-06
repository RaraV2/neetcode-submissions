class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
       std::unordered_set<int> s1;
       for(auto it: nums)
       {
            if(s1.count(it) == 1) return true;
            s1.insert(it);
       }
        return false;
    }
};