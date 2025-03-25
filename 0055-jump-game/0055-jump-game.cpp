class Solution {
public:
    int dp[10001];
    bool rec(int index,vector<int>& nums,int n)
    {
        //base case
        if(index==n-1)return true;
        //pruning case
        if(index>=n)return false;
        //cache check
        if(dp[index]!=-1)return dp[index];
        //compute and transition
        bool a=false;
        for(int i=1;i<=nums[index];i++)
        {
            a|=rec(index+i,nums,n);
        }
        dp[index]=a;
        return dp[index];

    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
       return rec(0,nums, nums.size());
    }
};