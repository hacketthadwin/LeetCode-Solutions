class Solution {
public:
    int dp[30001][2]; 
    
    int rec(int index, vector<int>& prices, int n, int istaken) {
        // Base case
        if (index == n) {
            return (istaken == 0) ? 0 : -1e9;
        }

        // Cache check
        if (dp[index][istaken] != -1) return dp[index][istaken];

        // Compute and transition
        int ans = rec(index + 1, prices, n, istaken);
        // When you buy a stock, you are spending money (losing money at that moment). This is why we subtract the price of the stock.

        // When you sell a stock, you are gaining money, so we add the price of the stock.
        if (istaken == 0) {
            ans = max(ans, -prices[index] + rec(index + 1, prices, n, 1));
        } else {
            ans = max(ans, prices[index] + rec(index + 1, prices, n, 0));
        }

        return dp[index][istaken] = ans;
    }

    int ultarec(vector<int>& prices,int n)
    {
        int dpi[30001][2];
        dpi[n][0]=0;
        dpi[n][1]=-1e9;
        for(int i=n-1;i>=0;i--)
        {
            dpi[i][0]=max(dpi[i+1][0],-prices[i]+dpi[i+1][1]);
            dpi[i][1]=max(dpi[i+1][1],prices[i]+dpi[i+1][0]);
        }
        return dpi[0][0];

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        // return rec(0, prices, n, 0);
        return ultarec(prices,n);
    }
};