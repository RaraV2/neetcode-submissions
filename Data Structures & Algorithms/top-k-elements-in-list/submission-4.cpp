class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map{};
        vector<vector<int>> bucket(nums.size()+1);
        vector<int> answer{};

        for(const auto &x : nums){
            map[x]++;
        }

        for(const auto &m : map){
            bucket[m.second].push_back(m.first);
        }

        for(auto it = bucket.rbegin(); it != bucket.rend(); ++it){

            for(const auto &z : *it){
                if(k == 0) return answer;
                answer.push_back(z);
                --k;
            }
        }
        return answer;
    }
};
