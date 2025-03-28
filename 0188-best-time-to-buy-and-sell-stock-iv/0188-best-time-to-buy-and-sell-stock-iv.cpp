class Solution {
public:
    //     int dp[1001][2][101]; 
    
    // int rec(int index, vector<int>& prices, int n, int istaken,int numoftaken,int k) {
    //     // Base case
    //     if (index == n) {
    //         return (istaken == 0 && numoftaken<=k) ? 0 : -1e9;
    //     }
    //     //pruning case
    //     if(numoftaken>k)return -1e9;
    //     // Cache check
    //     if (dp[index][istaken][numoftaken] != -1) return dp[index][istaken][numoftaken];

    //     // Compute and transition
    //     int ans = rec(index + 1, prices, n, istaken,numoftaken,k);
    //     // When you buy a stock, you are spending money (losing money at that moment). This is why we subtract the price of the stock.

    //     // When you sell a stock, you are gaining money, so we add the price of the stock.
    //     if (istaken == 0) {
    //         ans = max(ans, -prices[index] + rec(index + 1, prices, n, 1,numoftaken+1,k));
    //     } else {
    //         ans = max(ans, prices[index] + rec(index + 1, prices, n, 0,numoftaken,k));
    //     }

    //     return dp[index][istaken][numoftaken] = ans;
    // }
        int ultarec(vector<int>& prices, int n,int k) {
    int dp[n+1][2][k+2];

    // Base Case Initialization
    for (int istaken = 0; istaken < 2; istaken++) {
        for (int numoftaken = 0; numoftaken < k+1; numoftaken++) {
            dp[n][istaken][numoftaken] = 0;
        }
    }
    

    // Bottom-Up DP Transition
    for (int index = n - 1; index >= 0; index--) {
        for (int numoftaken = 0; numoftaken < k+1; numoftaken++) {
            // Case 1: Not Holding a Stock
            dp[index][0][numoftaken] = dp[index + 1][0][numoftaken]; // No action
            if (numoftaken < k) { // Can still buy
                dp[index][0][numoftaken] = max(dp[index][0][numoftaken], -prices[index] + dp[index + 1][1][numoftaken + 1]);
            }

            // Case 2: Holding a Stock
            dp[index][1][numoftaken] = dp[index + 1][1][numoftaken]; // No action
            if (numoftaken > 0) { // Can sell
                dp[index][1][numoftaken] = max(dp[index][1][numoftaken], prices[index] + dp[index + 1][0][numoftaken]);
            }
        }
    }

    // Final Answer
    return dp[0][0][0];
}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // memset(dp, -1, sizeof(dp));
        //return rec(0, prices, n, 0,0,k);
        return ultarec(prices,n,k);
    }
};