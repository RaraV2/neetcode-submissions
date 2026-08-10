class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        
        int k{};
        long long tempTime{};
        int avgRate{},maxRate{},midRate{},l{},r{};
        int size{static_cast<int>(piles.size())};

        maxRate = *max_element(piles.begin(),piles.end());

        l = 1;
        r = maxRate;

        while(l <= r){

            midRate = l + (r-l)/2;
            tempTime = 0;

            for(const auto &x : piles){
                int bananaCount = x;
                tempTime += ceil(static_cast<double>(x)/ midRate);
            }

            if(tempTime <= h) {
                k = midRate;
                r = midRate - 1;
            }
            else{

                l = midRate + 1;
            }
        }

        return k;
    }
};
