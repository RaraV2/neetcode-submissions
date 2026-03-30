class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> m;
        for(auto x: nums)
        {
            if(!m.count(x)) m[x] = 1;
            m[x]++;
        }
        
        vector<pair<int,int>> temp;
        for(auto x: m)
        {
            temp.emplace_back(x.second,x.first);
        }
        sort(temp.rbegin(),temp.rend()); //sorts in reverse order   rend()  ...... rbegin()
                                                                    //end         start                 
        vector<int> ans;
        for(int i = 0;i<k;i++)
        {
            ans.emplace_back(temp[i].second);
        }
         return ans;
    }
};
