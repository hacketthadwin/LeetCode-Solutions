class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        vector<pair<int,int>> v;
        for (auto &p : points) {
            v.push_back({p[0], p[1]});
        }

        sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first != b.first) 
                return a.first > b.first;
            return a.second < b.second;
        });

        int n = v.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int minY = INT_MAX;
            for (int j = i+1; j < n; j++) {
                if (v[j].second >= v[i].second && v[j].second < minY) 
                {
                    count++;
                    minY = v[j].second;
                }

            }
        }

        return count;

    }
};