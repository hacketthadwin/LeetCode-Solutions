class Solution {
public:
//this is similar to palindrome partition 1,2 same modified mcm concept
    int n;
    int dp[2001][2001];
    bool pal[2001][2001];
    int rec(const string &s, int k, int i) {
        //base case
        if (i == n) 
        {
            if(k==1)
            {
                return 0;
            }
            else
            {
                return 100000;
            }
        }
        //pruning case
        if (k == 1)
        {
            if(pal[i][n-1]==true)return 0;
            return 1;
        }
        //cache check
        if (dp[i][k] != -1) return dp[i][k];
        //compute and transition
        int ans = 1e9;
        for (int p = i; p < n-k+1; p++) //i did this n-k+1 because i want to distribute it to k parts and then find minimum what the bug was happening was it was checking whole string even if k>1, and if the string is palindrome then it was returning 0, eg "aea" and k=2;
        {
            int ck=1;
            if(pal[i][p]==true)ck=0;
            int temp = ck + rec(s, k - 1, p + 1);
            ans = min(ans, temp);
        }

        return dp[i][k] = ans;
    }
    bool checkPartitioning(string s) {
        memset(dp,-1,sizeof(dp));
        n = s.size();
                memset(pal, false, sizeof(pal));

        // Precompute palindrome substrings from i to j
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(i == j) {
                    pal[i][j] = true;
                } else if(j == i + 1) {
                    pal[i][j] = (s[i] == s[j]);
                } else {
                    pal[i][j] = (s[i] == s[j]) && pal[i+1][j-1];
                }
            }
        }
        int ans=rec(s,3,0);
        if(ans==0)return true;
        return false;
        
    }
};