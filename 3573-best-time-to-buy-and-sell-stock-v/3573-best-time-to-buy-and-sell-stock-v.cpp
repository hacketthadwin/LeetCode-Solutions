class Solution {
public:
    
    long long rep(int indx, vector<int>& prices, int k,vector<vector<long long>>&dp)
    {
        //base case
        if(indx>=prices.size())return 0;
        //cache check
        if(dp[indx][k]!=-1)return dp[indx][k];
        //pruning case
        if(k==0)return 0;
        //cache check
        //compute and transition
        long long ans=0;
        long long profit1=0,profit2=0;
        for(int i=indx+1;i<prices.size();i++)
        {
            //if i do a transaction (no matter normal or short selling)
            profit1=max(profit1,abs(prices[i]-prices[indx]) + rep(i+1,prices,k-1,dp));
            //if i don't do any transaction on that day that is i skipped that day for a better future
            profit2=max(profit2,rep(i,prices,k,dp));
            ans=max(profit1,profit2);
        }
        return dp[indx][k]=ans;
        
    }
    long long maximumProfit(vector<int>& prices, int k) {
        // vector<vector<long long>>dp(prices.size()+1,vector<long long>(k+1,-1));
        // // return rep(0,prices,k,dp);
        // for(int i=0;i<dp.size();i++)
        // {
        //     dp[i][0]=0;
        // }
        // for(int i=1;i<=k;i++)
        // {
        //     dp[prices.size()][i]=0;
        // }
        
        // for(int i=prices.size()-1;i>=0;i--)
        // {
        //     for(int j=1;j<=k;j++)
        //     {
        //         long long ans=0;
        // long long profit1=0,profit2=0;
        //         for(int c=i+1;c<prices.size();c++)
        //         {
        //             //if i do a transaction (no matter normal or short selling)
        //             profit1=max(profit1,abs(prices[i]-prices[c]) + dp[c+1][j-1]);
        //             //if i don't do any transaction on that day that is i skipped that day for a better future
        //             profit2=max(profit2,dp[c][j]);
        //             ans=max(profit1,profit2);
        //         }
        //         dp[i][j]=ans;
        //     }
        // }

        // return dp[0][k];

        /*--------------------------------------------------------------------------*/
    int n = prices.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 1; j <= k; j++) {
        dp[n][j] = 0;
    }

    for (int j = 1; j <= k; j++) {
        // Pre-calculating suffix arrays for the current transaction count j
        vector<long long> suffixMaxNormal(n + 1, -1e18);
        vector<long long> suffixMaxShort(n + 1, -1e18);

        for (int c = n - 1; c >= 0; c--) {
            suffixMaxNormal[c] = max(suffixMaxNormal[c + 1], (long long)prices[c] + dp[c + 1][j - 1]);
            suffixMaxShort[c] = max(suffixMaxShort[c + 1], (long long)-prices[c] + dp[c + 1][j - 1]);
        }

        for (int i = n - 1; i >= 0; i--) {
            long long profit1 = 0, profit2 = 0;

            // Replaces the 'c' loop: 
            // profit1 handles both normal and short selling using suffix max/min logic
            profit1 = max(-prices[i] + suffixMaxNormal[i + 1], prices[i] + suffixMaxShort[i + 1]);
            
            // profit2 is skipping the current day i
            profit2 = dp[i + 1][j];

            dp[i][j] = max(profit1, profit2);
        }
    }

    return dp[0][k];
    }
};