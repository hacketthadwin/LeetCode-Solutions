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
// We sort the points by x in descending order, and only if the x’s are the same, we sort by y in ascending order.
// This means the y’s are not globally sorted, they’re only ordered within groups of equal x.
// That’s why we need minY: it keeps track of the lowest y encountered so far while scanning, ensuring the “no point inside the rectangle” condition is respected for all x values, not just within the same x group.