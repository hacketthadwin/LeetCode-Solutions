class Solution {
    //the bottom up approach of this code is very strange, common, but difficult to understand
public:
int dp[105];
int rec(vector<int>& nums,int n)
{
    //base case
    if(n<=0)return 0;
    //cache check
    if(dp[n]!=-1)return dp[n];
    //compute and transition
    int ans1= nums[n-1]+rec(nums,n-2);
    int ans2= rec(nums,n-1);
    int ans= max(ans1,ans2);
    return dp[n]=ans;
}
    int rob(vector<int>& nums) {
        // //this literal just like O(1) code, technically O(n) but n=100, so does it matter?
        // vector<int>t(nums.size()+1,0);
        // //t[i] denotes maximum money till ith house
        // t[1]=nums[0];
        // for(int i=2;i<=nums.size();i++)
        // {
        //     //stealing from current house and checking the maximum value till (i-2)th house, because we cannot check from (i-1)th house
        //     int steal=nums[i-1]+t[i-2];
        //     //same for skip, choosing the last house value only,thus skipping current house value
        //     int skip=t[i-1];

        //     //choosing maximum value till now
        //     t[i]=max(steal,skip);
        // }
        // return t[nums.size()];
        memset(dp,-1,sizeof(dp));
        return rec(nums,nums.size());
    }
};