class Solution {
public:
    int dp[961][961]; // 31*31 = 961, as per constraints

    bool solve(string& s1, string& s2, int i1, int j1, int i2, int j2) {
        int len = j1 - i1 + 1;
        int key1 = i1 * 31 + j1;
        int key2 = i2 * 31 + j2;

        int& val = dp[key1][key2];
        if (val != -1) return val;

        string a = s1.substr(i1, len);
        string b = s2.substr(i2, len);

        if (a == b) return val = true;

        string sorted_a = a;
        string sorted_b = b;
        sort(sorted_a.begin(), sorted_a.end());
        sort(sorted_b.begin(), sorted_b.end());
        if (sorted_a != sorted_b) return val = false;

        for (int k = 1; k < len; k++) {
            // No swap
            if (
                solve(s1, s2, i1, i1 + k - 1, i2, i2 + k - 1) &&
                solve(s1, s2, i1 + k, j1, i2 + k, j2)
            ) return val = true;

            // With swap
            if (
                solve(s1, s2, i1, i1 + k - 1, j2 - k + 1, j2) &&
                solve(s1, s2, i1 + k, j1, i2, j2 - k)
            ) return val = true;
        }

        return val = false;
    }

    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        int n = s1.length();
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, n - 1, 0, n - 1);
    }
};
