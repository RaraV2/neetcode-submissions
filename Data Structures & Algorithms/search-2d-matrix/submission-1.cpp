class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int l{},r{},mid{},size{static_cast<int>(matrix[0].size())};
        for(const auto &x : matrix){
            l = 0;
            r = size - 1;
            
            while(l <= r){
                mid = (l+r)/2;
                if(x[mid] == target) return true;
                else if(x[mid] > target){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};
