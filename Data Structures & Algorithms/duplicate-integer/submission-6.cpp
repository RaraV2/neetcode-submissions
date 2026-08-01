class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> hash{};
        for(auto &x : nums) {
            if( hash.find(x) != hash.end()) return true; 
            else hash.insert(x);
        }
        
        return false;
    }
};