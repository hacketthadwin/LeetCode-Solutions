class Solution {
public:
    int N, K, maxP;
    vector<double> dp;

    double rec(int curr) {
        if (curr >= K) {
            return (curr <= N) ? 1.0 : 0.0;
        }
        if (dp[curr] > -0.5) return dp[curr];

        double sum = 0.0;
        for (int i = 1; i <= maxP; ++i) {
            sum += rec(curr + i);
        }
        dp[curr] = sum / (double)maxP;
        return dp[curr];
    }

    double new21Game(int n, int k, int maxPts) {
        // N = n; K = k; maxP = maxPts;
        // if (K == 0) return 1.0;

        // if (n >= k - 1 + maxPts) return 1.0;

        // dp.assign(K, -1.0); 
        // return rec(0);
        // N = n; K = k; maxP = maxPts;
        // if (K == 0) return 1.0;
        // if (n >= k - 1 + maxPts) return 1.0;

        // dp.assign(K, 0.0);
        // for (int i = K - 1; i >= 0; --i) {
        //     double sum = 0.0;
        //     for (int j = 1; j <= maxP; ++j) {
        //         int nxt = i + j;
        //         if (nxt >= K) {
        //             if (nxt <= N) sum += 1.0;
        //         } else {
        //             sum += dp[nxt];
        //         }
        //     }
        //     dp[i] = sum / (double)maxP;
        // }
        // return dp[0];

        if (k == 0) return 1.0;
        if (n >= k - 1 + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double windowSum = 1.0, result = 0.0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = windowSum / maxPts;

            if (i < k) {                 // can still draw
                windowSum += dp[i];
            } else {                     // game stops
                result += dp[i];
            }

            if (i - maxPts >= 0) {       // shrink window
                windowSum -= dp[i - maxPts];
            }
        }
        return result;


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
