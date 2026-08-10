class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse(heights.size()), nse(heights.size());
        // {number,index}
        stack<pair<int, int>> temp;
        int currElt{};

        for (int i = 0; i < heights.size(); ++i) {
            currElt = heights[i];
            // to handle first element, its has no pse
            if (temp.empty()) {
                pse[i] = -1;
                temp.push({currElt, i});
                continue;
            } else if (currElt < temp.top().first) {
                while (!temp.empty() && (currElt < temp.top().first)) {
                    temp.pop();
                }
                if (temp.empty()) {
                    pse[i] = -1;
                    temp.push({currElt, i});
                    continue;
                } else if (currElt == temp.top().first) {
                    // Equal element became the new top after popping
                    pse[i] = pse[temp.top().second];
                    temp.push({currElt,i});
                    continue;
                }
                pse[i] = temp.top().second;
                temp.push({currElt, i});
            } else if (currElt == temp.top().first) {
                pse[i] = pse[temp.top().second];
                temp.push({currElt, i});
            } else if (currElt > temp.top().first) {
                // the first one's position will be
                // the last bound for both
                pse[i] = temp.top().second;
                temp.push({currElt, i});
            }
        }

        // empty a stack
        temp = std::stack<pair<int, int>>();

        // nse
        int rBound = heights.size();
        // rBound not height.size()-1
        // if heights = [5]
        // nse - pse - 1 = 0 - (-1) - 1 == 0
        // but width is 1
        for (int i = rBound - 1; i >= 0; --i) {
            currElt = heights[i];
            // to handle first element, its has no pse
            if (temp.empty()) {
                nse[i] = rBound;
                temp.push({currElt, i});
                continue;
            } else if (currElt < temp.top().first) {
                while (!temp.empty() && (currElt < temp.top().first)) {
                    temp.pop();
                }
                if (temp.empty()) {
                    nse[i] = rBound;
                    temp.push({currElt, i});
                    continue;
                } else if (currElt == temp.top().first) {
                    // Equal element became the new top after popping
                    pse[i] = pse[temp.top().second];
                    temp.push({currElt,i});
                    continue;
                } else
                    nse[i] = temp.top().second;
                temp.push({currElt, i});
            } else if (currElt == temp.top().first) {
                nse[i] = nse[temp.top().second];
                temp.push({currElt, i});
            } else if (currElt > temp.top().first) {
                // the first one's position will be
                // the last bound for both
                nse[i] = temp.top().second;
                temp.push({currElt, i});
            }
        }

        int maxArea{}, area{};
        for (int i = 0; i < rBound; ++i) {
            area = (nse[i] - pse[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
