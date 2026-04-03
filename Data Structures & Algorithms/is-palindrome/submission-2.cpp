class Solution {
public:
    bool isPalindrome(string s) {

        if(s.empty()) return true;

        auto L{s.begin()};
        auto R{s.end() - 1};
        
        while( L < R )
        {
            while( L < R && !isalnum(*L)) L++;
            while( R > L && !isalnum(*R)) R--;
            
            if(tolower(*L)== tolower(*R)){L++;R--;}
            else return false;
        }
        return true;
    }
};
