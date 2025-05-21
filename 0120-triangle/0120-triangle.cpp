class Solution {
public:
int dp[205][40001];
int rec(vector<vector<int>>& triangle,int n,int i)
{
    //base case
    if(n==triangle.size())
    {
        return 0;
    }

    int ans = triangle[n][i] + min(rec(triangle, n + 1, i), rec(triangle, n + 1, i + 1));

    return ans;
}
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
         return rec(triangle, 0, 0); // start from top at row 0, index 0
    }
};