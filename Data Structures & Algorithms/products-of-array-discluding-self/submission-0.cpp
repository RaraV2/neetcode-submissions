class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> output(nums.size(),0);
        set<int> zeropos;
        int product{1};
        int k{0};

        for(auto &x: nums)
        {   
            if(x == 0) {
                zeropos.insert(k); //postion where 0 appear in ascending order
                k++;
            }
            else product *= x;
            k++;
        }


        if(zeropos.size() > 1) return output; //if no of 0's >1 all output[i] = 0

        else if(zeropos.size() == 1)
        {
            output[*zeropos.begin()] = product; //sirf zero ki pos pe non zero val hogi
            
            return output;
        }

        else{

            for(int i = 0; i < nums.size(); i++)
            {
                output[i] = product/nums[i];
            }
            return output;
        }
    }
};
