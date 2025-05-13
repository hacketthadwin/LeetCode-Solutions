class Solution {
public:
int dp[201][20001];

//this was approach 1
    int rec(vector<int>& nums, int n, int sum, int currsum) {
        // base case
        if (n == 0) {
            if (currsum == sum - currsum)
                return 0;
            else
                return -1e9;
        }
        //cache check
        if(dp[n][currsum]!=-1)return dp[n][currsum];
        // compute and transition
        if (currsum + nums[n - 1] <= sum - currsum) {
            return dp[n-1][currsum] = max(
                rec(nums, n - 1, sum, currsum + nums[n - 1]),
                rec(nums, n - 1, sum, currsum)
            );
        } else {
            return dp[n-1][currsum] = rec(nums, n - 1, sum, currsum);
        }
    }
    
    //my next optimised approach can be to check if i can create the sum/2 from given elements, but before that we just need to check, if sum%2!=0 then it is never possible that we can divide the sum into two equal parts
    //so our target is to create sum/2 from the given array, if we succeed then we can return true, or else return false
    //this was basically subset sum problem

bool dp2[201][10001];
bool visited[201][10001];  // to mark visited states

bool rec2(vector<int>& nums, int n, int target)
{
    //basecase
    if (n == 0) return target == 0;
    //cache check
    if (visited[n][target]) return dp2[n][target];
    //compute and transition
    bool take = false;
    //2 cases and 1 case
    if (target - nums[n - 1] >= 0)
    {dp2[n][target]= rec2(nums, n - 1, target - nums[n - 1])||rec2(nums, n - 1, target);}
    else
    {
        dp2[n][target]= rec2(nums, n - 1, target);
    }

    visited[n][target] = true;
    return dp2[n][target];
}


    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(nums.begin(), nums.end(), 0);
    //  int ans2 = rec(nums, nums.size(), sum, 0);
        if (sum % 2 != 0) return false;

        memset(dp2, false, sizeof(dp2));
        memset(visited, false, sizeof(visited));

        return rec2(nums, nums.size(), sum / 2);
    }
};
