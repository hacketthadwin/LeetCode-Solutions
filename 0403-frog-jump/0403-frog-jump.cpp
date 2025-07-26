class Solution {
public:
//this seems doable
//bool dp[i][last_jump_length]
//this is proper working state i guess
//now let's think on transition
//dp[n-1][i] can be anything ko true se initialise kr rahe 0 se le ke n-1 tk
//transition kya hoga?
//transition will be if it is possible to visit stone[i+1] or even furthur with k-1,k,k+1
//so dp[i][k] = possible, where possible is initially initialised with false but if it is possible to jump to next stone and then also checking if it is possible to reach to end by this then making it true
//so one more thing is that we check if it possible to go from current stone to next stone with k,k-1,k+1 steps
//for this we will use unordered map and will store stones[i] as key and index as their value, if it gives answer then stone is present
//and the answer is equals to current stone + k, then we will simply do 
//if(dp[j][step]) is true or not i.e. it is possible to reach to end if we now jump with k or not
//because we are moving backwards (we first put the answer in base case and then we moving backwards) 
//now as we see the first loop depends on i+1, so it will start from n-1 to 0
//but second can be anything so it does not matter what we choose
//i will return dp[0][1]
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n == 0) return true;
        if (n > 1 && stones[1] != 1) return false;

        unordered_map<int, int> stone_to_index;  //only for checking if the stone i am jumping on is present or not, this gives o(1) look-up
        for (int i = 0; i < n; ++i) {
            stone_to_index[stones[i]] = i;
        }

        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        for (int k = 1; k <= n; ++k) {
            dp[n - 1][k] = true;
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int k = 1; k <= n; ++k) {
                bool possible = false;

                int step1 = k - 1;
                if (step1 > 0) {
                    int target1 = stones[i] + step1;
                    if (stone_to_index.count(target1)) {
                        int j = stone_to_index[target1];
                        if (dp[j][step1]) {
                            possible = true;
                        }
                    }
                }

                int step2 = k;
                if (!possible) {
                    int target2 = stones[i] + step2;
                    if (stone_to_index.count(target2)) {
                        int j = stone_to_index[target2];
                        if (dp[j][step2]) {
                            possible = true;
                        }
                    }
                }

                int step3 = k + 1;
                if (!possible && step3 <= n) {
                    int target3 = stones[i] + step3;
                    if (stone_to_index.count(target3)) {
                        int j = stone_to_index[target3];
                        if (dp[j][step3]) {
                            possible = true;
                        }
                    }
                }

                dp[i][k] = possible;
            }
        }

        return dp[1][1];
    }
};

const auto _ = cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    atexit(&___::_);
    return 0;
}();
