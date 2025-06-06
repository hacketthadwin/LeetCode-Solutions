class Solution {
public:
//this is mcm problem only
    int dp[51][51];
    int rec(vector<int>& values,int i,int j)
    {
        //base case
        if(i+1==j)return 0;  //changed the condition from i to i+1
        if(dp[i][j]!=-1)return dp[i][j];
        //compute and transition
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            int tempans= rec(values,i,k) + rec(values, k, j) + values[i]*values[k]*values[j];  //changed the condition from rec(values,i,k) + rec(values, k+1, j) to rec(values,i,k) + rec(values, k, j)
            ans= min(ans,tempans);
        }
        return dp[i][j]=ans;
        

    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        return rec(values,0,values.size()-1);
    }
};