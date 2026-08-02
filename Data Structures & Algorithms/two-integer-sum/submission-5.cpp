class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            std::unordered_map<int,int> NumPos{};
            int temp{0};
            for(auto const &x : nums) {
                NumPos[x] = temp++;
            }
            for(int i = 0; i < nums.size()-1;++i) {
                temp = target - nums[i];
                if(NumPos.contains(temp)) {
                    if(NumPos[temp] !=  i) 
                    return                        {min(i,NumPos[temp]),max(i,NumPos[temp])};
                }
            
            }
        }
};

