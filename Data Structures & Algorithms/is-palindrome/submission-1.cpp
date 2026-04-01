class Solution {
public:
//cant compare .begin() & .rbegin() both are different types
    bool isPalindrome(string s) {
        auto left = s.begin();
        auto right = s.end() - 1;  // last character

        while (left < right) {
            // skip non-alphanumeric
            while (left < right && !isalnum(*left)) ++left;
            while (left < right && !isalnum(*right)) --right;

            // compare (case insensitive)
            if (tolower(*left) != tolower(*right)) return false;

            ++left;
            --right;
        }

        return true;
    }
};