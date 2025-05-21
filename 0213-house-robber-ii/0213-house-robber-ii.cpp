class Solution {
public:

//ok so this was my code which is currently facing sum issues which need to be resolved, i tried using this method that if we can flag that if we have taken any one of the end element,then we cannot take another element
//but this is wrong because see if we mark that we are not going to take the first element for now and only take the last element but what if taking first element will give more answer than the last element and vice versa.
//so the best approach is to apply the code twice
//first from 1 to n
//second from 0 to n-1
// int dp[105][2];
// int rec(vector<int>& nums,int n,int taken)
// {
//     //base case
//     if(n<=0)return 0;
//     //cache check
//     if(dp[n][taken]!=-1)return dp[n][taken];
//     //compute and transition
//     int ans1=0;
//     ans1= nums[n-1]+rec(nums,n-2,taken);
//     int ans2= rec(nums,n-1,taken);
//     int ans= max(ans1,ans2);
//     return dp[n][taken]=ans;
// }

int dp[105][105];
int rec(vector<int>& nums,int n,int i)
{
    //base case
    if(n<=i)return 0;
    //cache check
    if(dp[n][i]!=-1)return dp[n][i];
    //compute and transition
    int ans1= nums[n-1]+rec(nums,n-2,i);
    int ans2= rec(nums,n-1,i);
    int ans= max(ans1,ans2);
    return dp[n][i]=ans;
}
    int rob(vector<int>& nums) {
               int n = nums.size();
        if (n == 1) return nums[0];

        // Case 1: First house taken
        memset(dp, -1, sizeof(dp));
        int take_first =rec(nums, n, 1); // last can't be taken

        // Case 2: First house not taken
        memset(dp, -1, sizeof(dp));
        int skip_first = rec(nums, n-1, 0); // last can be taken

        return max(take_first, skip_first);
    }
};