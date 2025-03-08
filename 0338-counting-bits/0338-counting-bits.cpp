class Solution {
public:
//so we have to count the number of numbers divisible by 2 in this;
    vector<int> countBits(int n) {
    //dp approach was difficult to find, so here it is
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
        //for every number from 0 to n, we will go to half of that number, check the number of ones in that number and if current number is odd, then adding one from that too
        //very awesome approach in o(n)

    }
};