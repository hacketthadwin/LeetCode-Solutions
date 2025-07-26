class Solution {
    string s1, s2;
    int n;
    int dp[31][31][31][31]; // dp[i1][j1][i2][j2]

    bool rec(int i1, int j1, int i2, int j2) {
        if (dp[i1][j1][i2][j2] != -1)
            return dp[i1][j1][i2][j2];

        int len = j1 - i1;

        // Base case: if substrings are equal
        if (s1.substr(i1, len) == s2.substr(i2, len))
            return dp[i1][j1][i2][j2] = 1;

        // Pruning: if they don't have same letters
        string sub1 = s1.substr(i1, len), sub2 = s2.substr(i2, len);
        sort(sub1.begin(), sub1.end());
        sort(sub2.begin(), sub2.end());
        if (sub1 != sub2)
            return dp[i1][j1][i2][j2] = 0;

        // Try all splits
        for (int k = 1; k < len; k++) {
            // No swap
            if (rec(i1, i1 + k, i2, i2 + k) &&
                rec(i1 + k, j1, i2 + k, j2))
                return dp[i1][j1][i2][j2] = 1;

            // Swap
            if (rec(i1, i1 + k, j2 - k, j2) &&
                rec(i1 + k, j1, i2, j2 - k))
                return dp[i1][j1][i2][j2] = 1;
        }

        return dp[i1][j1][i2][j2] = 0;
    }

public:
    bool isScramble(string _s1, string _s2) {
        s1 = _s1;
        s2 = _s2;
        n = s1.size();

        if (n != s2.size()) return false;

        memset(dp, -1, sizeof(dp));
        return rec(0, n, 0, n);
    }
};
