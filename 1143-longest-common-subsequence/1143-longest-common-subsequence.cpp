class Solution {
public:
    int dp[1001][1001];
    int m,n;
    string A, B;
    int rec(int i,int j)
    {
        //pruning case
        if(i>=m||j>=n)return 0;
        //cache check
        if(dp[i][j]!=-1)return dp[i][j];
        //compute/transition
        int ans=0;
        ans=max(ans,rec(i+1,j));
        ans=max(ans,rec(i,j+1));
        if(A[i]==B[j])ans=max(ans,1+rec(i+1,j+1));
        //save and return
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        m=text1.size();
        n=text2.size();
        A=text1;
        B=text2;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};