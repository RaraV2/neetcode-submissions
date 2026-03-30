class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<pair<int,int>> freq; // {count, number}
        int count = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
                count++;
            else
            {
                freq.push_back({count, nums[i-1]});
                count = 1;
            }
        }

        // last group
        freq.push_back({count, nums.back()});

        // sort by frequency
        sort(freq.rbegin(), freq.rend());

        vector<int> ans;
        for(int i = 0; i < k; i++)
            ans.push_back(freq[i].second);
            return ans;
    }
};