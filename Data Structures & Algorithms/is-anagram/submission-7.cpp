class Solution {
public:
    bool isAnagram(string s, string t) {

        std::unordered_map<char,int> CharCount{};
        for(auto const &x : s) {
            if(CharCount.find(x) != CharCount.end()) {
                CharCount[x]++;
            } 
            else CharCount.emplace(x,1);
        }

        for(auto const &x : t)  {
            if(CharCount.find(x) != CharCount.end()) {
                CharCount[x]--;
            } 
            else return false;
        }

        for (auto const &x : CharCount) {
            if (x.second != 0) {
                return false;
            }
        }

        return true;
        
    }
};
