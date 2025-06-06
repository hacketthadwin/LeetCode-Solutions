class Solution {
public:
int dp[301][301];
int rec(vector<vector<int>>& matrix,int m,int n)
{
    //base case
    if(m==0 || n==0)
    {
        return 0;
    }
    //cache check
    if(dp[m][n]!=-1)return dp[m][n];
    //compute and transition
    int ans=0;
    if(matrix[m-1][n-1]==1)
    {
        ans = (1 + min({rec(matrix,m-1,n),rec(matrix,m,n-1),rec(matrix,m-1,n-1)}));
    }
    return dp[m][n]=ans;
}
// int ultarec(vector<vector<int>>& matrix){

// }
    int countSquares(vector<vector<int>>& matrix) {
        //this was my logic, but it was wrong, as it was unable to check all elements of the square and therefore overcounts squares 
        int m=matrix.size();
        int n=matrix[0].size();
        // int ans=0;
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {

        //         for(int size=0;size<min(m-i,n-j);size++)
        //         {
        //             if(matrix[i][j]==1 && matrix[i+size][j]==1 && matrix[i][j+size]==1 && matrix[i+size][j+size]==1)
        //             {
        //                 ans++;
        //             }
        //             else
        //             {
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return ans;
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ans+=rec(matrix,i,j);
            }
        }
        return ans;
    }
};