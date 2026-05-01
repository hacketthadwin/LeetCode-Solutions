class Solution {
public:

int rec(int i,int j,int n,int m, vector<vector<int>>& grid, int k, vector<vector<vector<int>>>&dp)
{
    //base case
    if(i==(m-1) && j==(n-1))return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    //compute and transition
    int curr1=INT_MIN;
    if(i<m-1)
    {
        if((grid[i+1][j]==1 || grid[i+1][j]==2) && k>0)
        {   
            curr1=max(curr1,grid[i+1][j]+rec(i+1,j,n,m,grid,k-1,dp));
        }
        if(grid[i+1][j]==0)
        {
            curr1=max(curr1,rec(i+1,j,n,m,grid,k,dp));
        }
        
    }
    int curr2=INT_MIN;
    if(j<n-1)
    {   
        if((grid[i][j+1]==1 || grid[i][j+1]==2) && k>0)
        {   
            curr2=max(curr2,grid[i][j+1]+rec(i,j+1,n,m,grid,k-1,dp));
        }
        if(grid[i][j+1]==0)
        {
            curr2=max(curr2,rec(i,j+1,n,m,grid,k,dp));
        }
        
    }
    return dp[i][j][k]=max(curr1,curr2);
}
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>>dp(grid.size()+5,vector<vector<int>>(grid[0].size()+5,vector<int>(k+5,-1)));
        int ans= rec(0,0,grid[0].size(),grid.size(),grid,k,dp);
        if(ans<0)return -1;
        return ans;
    }
};