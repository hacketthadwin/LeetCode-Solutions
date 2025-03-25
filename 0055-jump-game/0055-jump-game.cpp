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
        for(int i=1;i<=nums[index];i++)
        {
            if(rec(index+i,nums,n))
            {
                dp[index]=true;
                return true;
            }
        }
        dp[index]=false;
        return dp[index];

    }
    bool ultarec(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>dp(10*n,0);
        dp[n-1]=1;
        bool a=false;
        for(int index=nums[0];index<=(n-1);index++)
        {
            for(int i=1;i<=nums[index];i++)
            {
                a|=dp[index+i];
                dp[index]=a;
            }
        }
        return dp[n-1];
    }
    bool canJump(vector<int>& nums) {
    //    return ultarec(nums);
    memset(dp,-1,sizeof(dp));
    return rec(0,nums,nums.size());
    }
};