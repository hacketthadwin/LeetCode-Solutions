class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<pair<int,int>> value1;
        vector<pair<int,int>> value2;
        int n = values.size();
        value1.reserve(n);
        value2.reserve(n);

        for (int i = 0; i < n; i++) 
        {
            value1.push_back({values[i] - i, i});
            value2.push_back({values[i] + i, i});
        }

        int ans = 0;
        int bestLeft = value2[0].first;

        for (int j = 1; j < n; j++) {
            ans = max(ans, bestLeft + value1[j].first); 
            bestLeft = max(bestLeft, value2[j].first);   
        }

        return ans;
    }
};
