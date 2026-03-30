class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        std::unordered_map<char,int> m1,m2; 
        for(auto x: s){
            if (m1.count(x) == 1) m1[x]++;
            else m1[x] = 1;
        }
        for(auto x: t){
            if (m2.count(x) == 1) m2[x]++;
            else m2[x] = 1;
        }

        return m1 == m2;
    }
};
