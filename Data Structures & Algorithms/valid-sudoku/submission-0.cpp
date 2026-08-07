class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rowMap;
        unordered_map<int, unordered_set<char>> colMap;
        unordered_map<int, unordered_set<char>> sq3x3Map;

        int X{}, Y{}, box{}, row{};
        for (const auto& t : board) {
            for (int col = 0; col < 9; ++col) {
                if (t[col] == '.') continue;

                if (rowMap[row].count(t[col]))
                    return false;
                else
                    rowMap[row].insert(t[col]);

                if (colMap[col].count(t[col]))
                    return false;
                else
                    colMap[col].insert(t[col]);

                X = row / 3;
                Y = col / 3;
                box = X * 3 + Y;
                if (sq3x3Map[box].count(t[col]))
                    return false;
                else
                    sq3x3Map[box].insert(t[col]);
            }
            ++row;
        }
        
        return true;
    }   
};
