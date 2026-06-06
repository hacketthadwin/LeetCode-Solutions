class Solution {
public:
// int dp[1001][1001];
// int rec(int idx,int jdx, string&s, string&t)
// {
//     if(jdx==t.size()) return 1;
//     if(idx==s.size()) return 0;
//
//     if(dp[idx][jdx]!=-1) return dp[idx][jdx];
//
//     int curr_ans=0;
//     for(int i=idx;i<s.size();i++)
//     {
//         if(s[i]==t[jdx])
//         {
//             curr_ans+=rec(i+1,jdx+1,s,t);
//         }
//     }
//     return dp[idx][jdx]=curr_ans;
// }

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][m]=1;
        }
        for(int j=m-1;j>=0;j--)
        {
            for(int i=n-1;i>=0;i--)
            {
                dp[i][j]=dp[i+1][j]; //skip it

                if(s[i]==t[j]) //take it
                {
                    dp[i][j]+=dp[i+1][j+1];
                }
            }
        }
        return (int)dp[0][0];
    }
};