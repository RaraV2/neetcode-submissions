class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> output(nums.size(),0);
        int zerocount{0};
        int zeropos{0};
        int product{1};
        int k{0};

        for(auto &x: nums)
        {   
            if(x == 0) {
                if (zerocount == 1) return output; //already 1 zero, if 2nd zero comes all output will be zero
                zerocount++; //postion where 0 appear in ascending order
                zeropos = k; //we need zero only once to get non zero array
                k++;
            }
            else product *= x;
            k++;
        }

        if(zerocount == 1)
        {
            output[zeropos] = product; //sirf zero ki pos pe non zero val hogi
            
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
