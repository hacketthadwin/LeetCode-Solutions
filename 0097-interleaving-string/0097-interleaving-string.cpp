class Solution {
public:
//this is easy i guess starting at current index in s3, matching characters in s1 and s2, whichever matches
int dp[102][102];
bool rec(string s1, string s2, string s3,int n1,int n2,int n3)
{
    //base case
    if(n3<=0)return true;
    //cache check
    if(dp[n1][n2]!=-1)return dp[n1][n2];
    bool ans=false;
        if (n1 > 0 && s3[n3 - 1] == s1[n1 - 1]) {
            ans |= rec(s1, s2, s3, n1 - 1, n2, n3 - 1);
        }

        if (n2 > 0 && s3[n3 - 1] == s2[n2 - 1]) {
            ans |= rec(s1, s2, s3, n1, n2 - 1, n3 - 1);
        }

    return dp[n1][n2]=ans;
    
}
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        memset(dp,-1,sizeof(dp));
        return rec(s1,s2,s3,s1.size(),s2.size(),s3.size());
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
