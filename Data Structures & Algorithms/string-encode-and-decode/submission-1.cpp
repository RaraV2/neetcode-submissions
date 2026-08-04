class Solution {
public:

    string encode(vector<string> &strs) {
        string s{};
        if(strs.empty()) return s;
        else{
        s += to_string(strs[0].length()) + '#' + strs[0];
        for(int i = 1; i < strs.size(); ++i)   {
            s += to_string(strs[i].length()) + '#' + strs[i];
        }
        return s;
      }
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs{};
        string delimitter{'#'};

        int pos{0};
        int index{0};
        while(index != s.length()) {
            string tempStringLength{};
            int stringLength{};
            string tempStr{};
            pos = s.find(delimitter,index);
            
            for(index; index < pos; ++index){
                tempStringLength += s[index];
            }
            // to move past --># index + 1
            ++index;

            stringLength = std::stoi(tempStringLength);
            for(int i = 0; i < stringLength;  ++i){
                tempStr += s[index + i];
            }
            index += stringLength;
            //to move after the word
            decoded_strs.push_back(tempStr);
        }

        return decoded_strs;
    }
};
