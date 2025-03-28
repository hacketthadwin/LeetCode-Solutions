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
        
        if (istaken == 0) {
            ans = max(ans, -prices[index] + rec(index + 1, prices, n, 1));
        } else {
            ans = max(ans, prices[index] + rec(index + 1, prices, n, 0));
        }

        return dp[index][istaken] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, prices, n, 0);
    }
};