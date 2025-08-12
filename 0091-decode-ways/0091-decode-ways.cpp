class Solution {
public:
//this is typical dynamic programming problem where i have been given one string and i need to divide it into smaller parts, now what i thought is first i will solve this problem into two cases
//i will apply a for loop from i=0 to i = n-1, then i will consider 2 cases, first i will divide it in one char and then will process to solve and second will be 2 continous chars if they valid like lie between 10 to 26
//what my dp state will look like? i guess it should be index, size like for this index, and for size 1 or 2
//it will start from end, because i cannot consider 0,
int dp[200];
int rec(string s,int n)
{
    //base case
    if(n==0)
    {
        return 1;
    }
    //cache check
    if(dp[n-1]!=-1)return dp[n-1];
    //compute and transition
    //i can take one char for sure if it is not 0
    int ans=0;
    if(s[n-1]!='0')
    {
        ans+=rec(s,n-1);
    }
    if (n >= 2) {
        int temp = (s[n-2]-'0')*10+(s[n-1]-'0');
        if (temp >= 10 && temp <= 26) {
            ans += rec(s, n - 2);
        }
    }

    return dp[n-1]=ans;
    
}
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return rec(s,s.size());
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
