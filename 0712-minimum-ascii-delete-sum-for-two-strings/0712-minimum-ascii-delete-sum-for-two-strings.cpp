class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //here we have state as dp[i][j] which stores the maximum ascii value of subsequence for s1 till i and s2 till j
        vector<vector<int>>dp(1002,vector<int>(1002,0));
        for(int i=s1.size()-1;i>=0;i--)
        {
            for(int j=s2.size()-1;j>=0;j--)
            {

                if(s1[i]==s2[j])
                {
                    dp[i][j]=max(dp[i][j],int(s1[i])+dp[i+1][j+1]);
                }
                dp[i][j] = max(dp[i][j],dp[i+1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j+1]);
            }
        }

        int total=0;
        for(int i=0;i<s1.size();i++)
        {
            total+=int(s1[i]);
        }
        for(int i=0;i<s2.size();i++)
        {
            total+=int(s2[i]);
        }

        total-=(2*(dp[0][0]));

        return total;
    }
};