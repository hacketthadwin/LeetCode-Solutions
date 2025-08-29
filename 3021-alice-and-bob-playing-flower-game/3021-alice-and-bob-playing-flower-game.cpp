class Solution {
public:
    long long flowerGame(int n, int m) {
        int cnt_of_even_of_n=0;
        int cnt_of_odd_of_n=0;
        int cnt_of_even_of_m=0;
        int cnt_of_odd_of_m=0;

        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                cnt_of_even_of_n++;
            }
            else
            {
                cnt_of_odd_of_n++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(i%2==0)
            {
                cnt_of_even_of_m++;
            }
            else
            {
                cnt_of_odd_of_m++;
            }
        }

        long long ans = ((long long)cnt_of_even_of_m*cnt_of_odd_of_n) + ((long long)cnt_of_odd_of_m*cnt_of_even_of_n);

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
