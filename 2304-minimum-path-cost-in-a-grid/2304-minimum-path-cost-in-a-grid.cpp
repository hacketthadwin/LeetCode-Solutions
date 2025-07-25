class Solution {
public:
int dp[100][100];
int rec(int i,int j, vector<vector<int>>& grid, vector<vector<int>>& moveCost, int rows, int cols)
{
    //base case
    if(i==rows-1)return 0;
    //cache check
    if(dp[i][j]!=-1)return dp[i][j];
    int temp_ans=1e9;
    for(int p=0;p<cols;p++)
    {
        int temp=moveCost[grid[i][j]][p]+grid[i+1][p]+rec(i+1,p,grid,moveCost,rows,cols);
        temp_ans=min(temp_ans,temp);
    }
    return dp[i][j]=temp_ans;
    
}
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) 
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n=grid.size();
        int m=grid[0].size();
        int ans=1e9;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            int temp_ans=grid[0][i]+rec(0,i,grid,moveCost,n,m);
            ans=min(ans,temp_ans);
        }
        return ans;
    }
};