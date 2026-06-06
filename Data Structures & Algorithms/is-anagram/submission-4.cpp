class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        std::unordered_map<char,int> map;
        for(auto x: s)
        {
            map[x]++;
        }

        for(auto x: t)
        {
            map[x]--;
        }

        for(auto x: map)
        {
            if(x.second != 0) return false;
        }

        return true;
    }
};
