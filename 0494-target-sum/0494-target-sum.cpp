class Solution {
public:
int dp[21][2001];
    int rec(vector<int>& nums, int target,int n)
    {
        //basecase
        if(n==0)
        {
            if(target==0){return 1;}
            else return 0;
        }
        if (target + 1000 < 0 || target + 1000 > 2000)
        return 0;
        //cache check
        if(dp[n][target+1000]!=-1)return dp[n][target+1000];
        int ans=0;
        //compute and transition
        ans+=rec(nums,target+nums[n-1],n-1);   //first if i am doing -
        ans+=rec(nums,target-nums[n-1],n-1);   //then if i am doing +

        return dp[n][target+1000]=ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,target,nums.size());
    }
};