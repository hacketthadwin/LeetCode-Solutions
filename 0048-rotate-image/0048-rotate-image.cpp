class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>ans(matrix.size(),vector<int>(matrix.size(),-1));
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int el=matrix[i][j];
                ans[j][n-i-1]=el;
            }
        }
        matrix=ans;
    }
};