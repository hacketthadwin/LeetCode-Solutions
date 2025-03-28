class Solution {
public:
        int dp[100001][2][4]; 
    
    int rec(int index, vector<int>& prices, int n, int istaken,int numoftaken) {
        // Base case
        if (index == n) {
            return (istaken == 0 && numoftaken<=2) ? 0 : -1e9;
        }
        //pruning case
        if(numoftaken>2)return -1e9;
        // Cache check
        if (dp[index][istaken][numoftaken] != -1) return dp[index][istaken][numoftaken];

        // Compute and transition
        int ans = rec(index + 1, prices, n, istaken,numoftaken);
        // When you buy a stock, you are spending money (losing money at that moment). This is why we subtract the price of the stock.

        // When you sell a stock, you are gaining money, so we add the price of the stock.
        if (istaken == 0) {
            ans = max(ans, -prices[index] + rec(index + 1, prices, n, 1,numoftaken+1));
        } else {
            ans = max(ans, prices[index] + rec(index + 1, prices, n, 0,numoftaken));
        }

        return dp[index][istaken][numoftaken] = ans;
    }

    int maxProfit(vector<int>& prices) {
               int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, prices, n, 0,0);
        // return ultarec(prices,n);
    }
};