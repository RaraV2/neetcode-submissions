class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        unordered_map<int,int> answerMap(nums.size());
        vector<int> answer(nums.size(),1);

        int i{0};
        while(i < nums.size()){
            for(int k = 0; k < nums.size(); ++k){
                if(k == i) continue;
                answer[k] *= nums[i];
            }
            ++i;
        }

        return answer;
    }
};
