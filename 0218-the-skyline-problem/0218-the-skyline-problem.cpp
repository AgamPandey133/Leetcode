class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<pair<int, int>> events;

        for (auto &b : buildings) {
            events.push_back({b[0], -b[2]}); 
            events.push_back({b[1],  b[2]}); 
        }

        sort(events.begin(), events.end());

        multiset<int> heights;
        heights.insert(0); 

        vector<vector<int>> ans;
        int prevHeight = 0;

        for (auto &[x, h] : events) {

            if (h < 0) {
                heights.insert(-h);
            } else {
                heights.erase(heights.find(h));
            }

            int currHeight = *heights.rbegin();

            if (currHeight != prevHeight) {
                ans.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return ans;
    }
};