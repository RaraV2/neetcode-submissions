class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length()) return false;
            std::unordered_map<char,int> freq{};
            for(auto const &x : s){
                ++freq[x];
            }

            for(auto const &x : t){
                --freq[x];
            }

            for(auto const &x : freq){
               if(x.second != 0) return false;
            }

            return true;
        }
};

