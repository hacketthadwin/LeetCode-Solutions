class Solution {
public:
int dp[2001];
bool pal[2001][2001];
//this checking of palindrome is giving me tle, instead i will just precompute all the palindromes in the srring from i to j 
// bool ispalindrome(const string &s, int start, int end) {
//     while (start < end) {
//         if (s[start++] != s[end--]) return false;
//     }
//     return true;
// }

    int rec(string s,int i)
    {
        //base case
        if(i==s.size())return 0;
        //cache check
        if(dp[i]!=-1)return dp[i];
        int ans=1e9;
        for(int k=i;k<s.size();k++)
        {
            // string t1=s.substr(i,k-i+1);
            //ok so i also learnt one more debugging thing that using the substr function continously can give you mle so make the palindrome function such that you dont need substr again and again...ajeeb issue
            if(pal[i][k])
            {
                //if i have already checked the i to k part then i dont need to use rec on it again and divide it...i do the two part ways only when i needed to go to smaller parts because they can give me answer, but if i already got my answer from checking one part, then going to check that part again is wrong approach...dont stick to mcm, try to learn how mcm works and its modifications
                    ans=min(ans, 1 + rec(s,k+1));
            }

        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
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

        if(pal[0][n-1]) return 0;

        return rec(s,0)-1;
    }
};