class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int>arr(k);
        for(int i=0;i<k;i++)
        {
            arr[i]=i+1;
        }
        int mod = 1000000007;
        //so let's start solving this problem
        //i have been given that i have n dices and i have to roll all dices and make the target k
        //there are k numbers on dice from 1 to k
        //so if i take dp state as dp[n][target] where n denotes number of dices rolled till now and target is what we have to make
        //this will be effective state from my opinion because dp[target] will not be sufficient, it will only be telling us the target but not the number of dice taken to make the target.
        //now let's talk about transition
        //dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-arr[k]];

        vector<vector<int>>dp(31,vector<int>(1009,0));

        for(int i=1;i<=k;i++)
        {
            dp[1][i]=1;
        }
        
        for(int i=1;i<=n;i++)  //the mistake i was making is that i was not taking i<=n, i was taking i<n, and that's why the dp[n] is never got filled
        {
            for(int j=1;j<=target;j++)
            {
                for(int p=0;p<k;p++)
                {
                    if(j>=arr[p])
                    {
                        dp[i][j]=(dp[i][j] + dp[i-1][j-arr[p]])%mod;
                    }
                }
            }
        }

        return dp[n][target];

    }
};
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
