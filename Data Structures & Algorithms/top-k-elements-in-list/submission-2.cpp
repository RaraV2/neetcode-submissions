class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer{};
        vector<pair<int,int>> topPairs{};
        unordered_map<int,int> map{};
        
        for(const auto &x : nums){
            map[x]++;
        }

        for(const auto &m : map){
            topPairs.push_back({m.second,m.first});
        }
    //. larget ...... smallest      rend [........... rbegin]
        sort(topPairs.rbegin(),topPairs.rend());
        
        for(int i = 0; i < k; ++i){
            answer.push_back(topPairs[i].second);
        }

        return answer;
    }
};
