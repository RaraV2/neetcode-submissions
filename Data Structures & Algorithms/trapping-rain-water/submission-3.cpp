class Solution {
public:
    int trap(vector<int>& h) {
        int l{0},r{static_cast<int>(h.size()-1)},maxL{h[l]},maxR{h[r]},totalArea{};
        //maxL is the bottleneck
        int tempArea{};
        while(l < r){
            if(maxL <= maxR){
                ++l;
                //since maxL is smaller, it's the bottle necj
                tempArea = maxL - h[l];
                if(tempArea < 0) totalArea += 0;
                else totalArea += tempArea;
                maxL = max(maxL,h[l]);
            }
            else{
                --r;
                tempArea = maxR - h[r];
                if(tempArea < 0) totalArea += 0;
                else totalArea += tempArea;
                maxR = max(maxR,h[r]);
            }
        }
        return totalArea;
    }
};
