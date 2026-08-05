class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> hash(nums.size());
        for(auto const &x : nums){
            hash.insert(x);
        }

        int maxConsecutiveLength{0};
        int tempLength{0};
        
        for(auto &x : hash) {
            if(!hash.count(x - 1)){
                int value = x;
                while(hash.count(value++)){
                    ++tempLength;
                }

                if(tempLength > maxConsecutiveLength) {
                    maxConsecutiveLength = tempLength;
                }

                tempLength = 0;
            }   
        }
        
        return maxConsecutiveLength;
    }
};
