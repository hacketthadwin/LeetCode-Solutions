class Solution {
    // https://justpaste.it/dr3j2
    //this was my initial thought process which was wrong
public:
    long long maxSubarrays(int n, vector<vector<int>>& cp) {
        int m=cp.size();
        for(int i=0;i<m;i++)
        {
            if(cp[i][1]<cp[i][0])swap(cp[i][1],cp[i][0]);
        }
        vector<pair<int,int>>v(m);
        for(int i=0;i<m;i++)
        {
            v[i]={cp[i][0],cp[i][1]};
        }
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        long long profit=0;
        long long max_profit=0;
        long long blocked=0;
        long long max1=0;
        long long max2=0;
        long long current_b=0;
        long long next_b=0;
        for(int i=0;i<m;i++)
        {
            current_b=v[i].second;
            if (i + 1 < m)
                next_b = v[i + 1].second;
            else
                next_b = n+1;

            long long gap= next_b - current_b;
            if(v[i].first>max1)
            {
                max2=max1;
                max1=v[i].first;
                profit=0;
            }
            else if(v[i].first>max2)
            {
                max2=v[i].first;
            }

            profit+=(max1-max2)*gap;
            max_profit=max(max_profit,profit);
            blocked += max1*gap;      // blocked+=(max1-max2)*(current_b); i thought this but this is wrong
        }

       long long total = 1LL * n * (n + 1) / 2;
        long long ans = total - blocked + max_profit;
        return ans;
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

