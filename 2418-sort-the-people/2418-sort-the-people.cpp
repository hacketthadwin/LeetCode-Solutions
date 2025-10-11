class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
                int n = heights.size();
        vector<string> ans;
        vector<pair<int, string>> helper; 
        for (int i = 0; i < n; i++) {
            helper.push_back({heights[i], names[i]});
        }
        sort(helper.rbegin(), helper.rend());
        for (int i = 0; i < n; i++)
            ans.push_back(helper[i].second);

        return ans;

    }
};