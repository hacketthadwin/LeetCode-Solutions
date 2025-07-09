class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>>dists;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            int dist= x*x + y*y;
            dists.push_back({dist,i});
        }
        sort(dists.begin(),dists.end());
        vector<vector<int>>ans;
        for(int i=0;i<k;i++)
        {
            int indx=dists[i].second;
            ans.push_back(points[indx]);
        }
        return ans;
    }
};