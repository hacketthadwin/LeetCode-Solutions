class Solution {
public:
int dp[1001][1001];
int rec(int i,int j,string&text1,string&text2){
    if(i>=text1.size() || j>=text2.size())
    {
        return 0;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    int cnt=0;
    if(text1[i]==text2[j])
    {
        cnt=max(cnt,rec(i+1,j+1,text1,text2)+1);
    }
    cnt=max(cnt,rec(i+1,j,text1,text2));
    cnt=max(cnt,rec(i,j+1,text1,text2));
    return dp[i][j]=cnt;
}
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,text1,text2);
    }
};