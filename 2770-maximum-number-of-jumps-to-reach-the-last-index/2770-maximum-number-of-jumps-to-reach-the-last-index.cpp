class Solution {
public:
int dp[1009];
int rec(int indx,vector<int>& nums, int target)
{
    if(indx==nums.size()-1)
    {
        return 1e9;
    }
    if(dp[indx]!=-1)return dp[indx];
    int ans=0;
    for(int i=indx+1;i<nums.size();i++)
    {
        if(abs(nums[i]-nums[indx])<=target)
        {
            ans=max(ans,1+rec(i,nums,target));
        }
    }
    return dp[indx]=ans;
}
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans= rec(0,nums,target);
        if(ans<1e9)
        {
            return -1;
        }
        return (ans-1e9);
    }
};