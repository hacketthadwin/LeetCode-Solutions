class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m=score.size();
        int n=score[0].size();
        vector<pair<int,int>>kth_row_vals;
        for(int i=0;i<m;i++)
        {
            kth_row_vals.push_back({score[i][k],i});
        }
        sort(kth_row_vals.begin(),kth_row_vals.end());
        reverse(kth_row_vals.begin(),kth_row_vals.end());
        vector<vector<int>>ans;
        for(int i=0;i<kth_row_vals.size();i++)
        {
            ans.push_back(score[kth_row_vals[i].second]);
        }
        return ans;
    }
};