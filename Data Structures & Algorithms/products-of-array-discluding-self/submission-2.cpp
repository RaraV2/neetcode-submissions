class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> output(nums.size());
        int prefixlastproduct{1};
        auto k = output.begin(); //points to 1st elemnt of prefixarray

        for(auto &x: nums)
        {
            *k = prefixlastproduct; //assigns to whatever k is pointing
            prefixlastproduct *= x;
            k++;
        }
        //output has prefix values now we just need to multiply with posfix

        int postfixlastproduct{1};
        auto f = output.rbegin();
        for(auto it = nums.rbegin(); it != nums.rend(); it++ )
        {
            *f *= postfixlastproduct; //assigns to whatever k is pointing
            postfixlastproduct *= *it;
            f++;
        }

        return output;

    }
};
