class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // number,days after warmer appears, index of it
        stack<pair<int,int>> tempStack{};
        vector<int> result(temperatures.size());

        int index{};
        for(const auto &x : temperatures){
            if(!tempStack.empty() && x >= tempStack.top().first) {
                while(!tempStack.empty() && x > tempStack.top().first){
                    int numIndex = tempStack.top().second;
                    result[numIndex] = index - numIndex;
                    tempStack.pop();
                }
                tempStack.push({x,index});
                ++index;
            }
            else {
            tempStack.push({x,index});
            ++index;
            }
        }
        //remaining temps who couldnt find warmer temps
        while(!tempStack.empty()){
            int numIndex = tempStack.top().second;
            result[numIndex] = 0;
            tempStack.pop();
        }

        return result;
    }
};
