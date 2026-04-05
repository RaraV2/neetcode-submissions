class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int L{0},R{heights.size() - 1}, maxArea{INT_MIN}, temp{0}
            , height{}, length{};


        while(L < R) {

            length = R - L;
            height = min(heights[L],heights[R]);
            temp = length * height;
            maxArea = max(temp,maxArea);

            if(heights[L] >= heights[R]) { R--;  }
            else L++;
        }    

        return maxArea;
    }
};
