class Solution {
public:
int dp[301][5001];
int rec(int amount,vector<int>coins,int n)
{
    //base case
    if(amount==0)
    {
        return 1;
    }
    //pruning case
    if(n==0)return 0;
    //cache check
    if(dp[n][amount]!=-1)return dp[n][amount];
    //compute and transition
    int ans=0;
    if(amount-coins[n-1]>=0)
    {
    ans+=rec(amount-coins[n-1],coins,n);
    ans+=rec(amount,coins,n-1);
    }
    else
    {
        ans+=rec(amount,coins,n-1);
    }

    return dp[n][amount]=ans;
    
}
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return rec(amount,coins,coins.size());

    }
};