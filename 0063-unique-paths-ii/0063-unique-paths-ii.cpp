class Solution {
public:
    int dp[105][105];
    int rec(int n,int m,vector<vector<int>>& grid)
    {
        //base case
        if(n==0 && m==0)return 1;
        if(n<0 || m<0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        int path1=0;
        int path2=0;
        if(n-1>=0 && grid[n-1][m]!=1)
        {
            path1=rec(n-1,m,grid);
        }
        
        if(m-1>=0 && grid[n][m-1]!=1)
        {
            path2=rec(n,m-1,grid);
        }

        return dp[n][m]=path1+path2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        memset(dp,-1,sizeof(dp));
        int ans= rec(n,m,grid);
        return ans;
    }
};