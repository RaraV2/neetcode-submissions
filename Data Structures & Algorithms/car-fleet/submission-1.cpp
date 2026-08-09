class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> carInfo(position.size());

        for (int index = 0; index < position.size(); ++index) {
            carInfo[index] = {position[index], speed[index]};
        }

        std::sort(carInfo.begin(), carInfo.end(),
                  [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                      return a.first > b.first;
                  });
        
        stack<double> fleets;
        for(const auto &x : carInfo){
            double time = static_cast<double>(target - x.first) / x.second;

            if(fleets.empty()) {
                fleets.push(time);
            }
            else if(time > fleets.top()){
                fleets.push(time);
            }
            else{
                // time <= currFleetTIme means will reach at same time
            }

        }

        return fleets.size();
    }
};
