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
        //see we require this condition because in the recursive calls i am increasing or decreasing the target, so this ensures that my target always remains in this range
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
    int ultarec(vector<int>& nums, int target,int n)
    {
        int ultadp[21][2001];
        memset(ultadp, 0, sizeof(ultadp));
        ultadp[0][1000] = 1;

        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<=2000;j++) //instead of looping from 1 to target+1000+1, we can loop through all indexes because i j+nums[i-1] may be outside the range of 1 to target+1000+1 but can be an option
            {
                // if (j + nums[i - 1] > 2000 || j + nums[i - 1] < 0)
                //     ultadp[i][j] = 0;  // this zeroes out the cell
                // else
                //     ultadp[i][j] += ultadp[i - 1][j + nums[i - 1]];

                // if (j - nums[i - 1] > 2000 || j - nums[i - 1] < 0)
                //     ultadp[i][j] = 0;  // this might overwrite previous value too!
                // else
                //     ultadp[i][j] += ultadp[i - 1][j - nums[i - 1]];

                //so the correct approach will be to not erase the value of 0 but just initialise the value with 0 and if there is any changes left then just making the change

                ultadp[i][j] = 0;  // initialize once

                if (j + nums[i - 1] <= 2000)
                    ultadp[i][j] += ultadp[i - 1][j + nums[i - 1]];

                if (j - nums[i - 1] >= 0)
                    ultadp[i][j] += ultadp[i - 1][j - nums[i - 1]];

            }
        }

        return ultadp[n][target+1000];


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        // return rec(nums,target,nums.size());
        return ultarec(nums,target,nums.size());
    }
};