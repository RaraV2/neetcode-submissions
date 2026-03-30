class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(auto x: strs)
        {
            string key = x;
            sort(key.begin(),key.end()); //sort the sele ted string which is key in map
            m[key].push_back(x);
            //pushes all anagram of the key( a word) in single vector
        }

        vector<vector<string>> answer;
        for(auto z: m)
        {
            answer.push_back(z.second);
        }
    return answer;
    }
};
