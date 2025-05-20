class Solution {
public:
int dp[13][10001];
    int rec(vector<int>& coins, int amount,int n)
    {
        //base case
        if (amount == 0) return 0;
        if (n == 0) return 1e9; // Infinite coins, means not possible
        //CACHE CHECK
        if(dp[n][amount]!=-1)return dp[n][amount];
        //compute and transition
        int ans = 1e9;
        if (coins[n - 1] <= amount) {
            ans = min(1 + rec(coins, amount - coins[n - 1], n),    //add 1 only if you are taking the coin
                      rec(coins, amount, n - 1));
        } else {
            ans = rec(coins, amount, n - 1);
        }
        return dp[n][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        sort(coins.begin(),coins.end());
        int res = rec(coins, amount, coins.size());
        return res >= 1e9 ? -1 : res;
    }
};