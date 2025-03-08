class Solution {
public:
    int rec(vector<int>& cost, int index,vector<int>&dp)
    {
        //basecase
        if(index>=cost.size())
        {
            return 0;
        }
        //cache check
        if(dp[index]!=-1)return dp[index];
        //compute and transition
        dp[index]= cost[index] + min(rec(cost,index+1,dp),rec(cost,index+2,dp));
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1);
        return min(rec(cost,0,dp),rec(cost,1,dp));
    }
};