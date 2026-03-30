class Solution {
public:

    string encode(vector<string>& strs) {

        string finalStr{};
        for(const auto& x : strs)
        {
            finalStr += to_string(x.length()) + "#" + x;
        }

        return finalStr;
    }

    vector<string> decode(string finalStr) {
        vector<string> decodedString{};
        size_t ini = 0;

        while(1)
        {   
            size_t pos = finalStr.find('#',ini); //pos = points to #
            if(pos == string::npos) return decodedString;
            string noOfChars = finalStr.substr(ini, pos - ini); //(start, No of char to read)
            int lengthtoread = stoi(noOfChars);
            string temp{};

            temp = finalStr.substr(pos + 1, lengthtoread);
            ini = (pos + 1) + lengthtoread; //at start char of next word
            
            decodedString.push_back(temp);

        }


    }
};
