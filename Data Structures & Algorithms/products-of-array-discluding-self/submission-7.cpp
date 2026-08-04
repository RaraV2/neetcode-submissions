class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> prefixArray(nums.size(),1);
        vector<int> postfixArray(nums.size(),1);

        for(int i = 0; i < nums.size() - 1; ++i) {
            prefixArray[i+1] *= prefixArray[i] * nums[i]; 
        }

        for(int i = nums.size() - 1; i > 0; --i){
            postfixArray[i-1] = postfixArray[i] * nums[i];
        } 

        vector<int> answer(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            answer[i] = prefixArray[i] * postfixArray[i];
        }

        return answer;
    }
};
