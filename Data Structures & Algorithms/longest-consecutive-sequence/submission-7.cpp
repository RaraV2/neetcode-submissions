class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> hash;

        for(const auto &x : nums){
            hash.insert(x);
        }

        int maxConsecutiveLength{0};
        int tempLength{};
        
        for(auto it = hash.begin(); it != hash.end(); ++it)   {
            
            if(hash.count(*it + 1) ) {
                tempLength++;
            }
            else{
                tempLength++;
                //for last element that doesnt have next conse..
                // but it's counted as well
                if(tempLength > maxConsecutiveLength) {
                    maxConsecutiveLength = tempLength;
                    tempLength = 0;
                }
                else tempLength = 0;
            }
        }     

        //if all are consecutive
        if(tempLength > maxConsecutiveLength) {
            tempLength = maxConsecutiveLength;
        }

        return maxConsecutiveLength;
    }
};
