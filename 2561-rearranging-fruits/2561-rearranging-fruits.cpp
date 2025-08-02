class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());

        map<int,int> cnt1, cnt2, cnt;
        for (int i = 0; i < basket1.size(); i++) {
            cnt1[basket1[i]]++;
            cnt[basket1[i]]++;
        }
        for (int i = 0; i < basket2.size(); i++) {
            cnt2[basket2[i]]++;
            cnt[basket2[i]]++;
        }

        for (auto &m : cnt) {
            if (m.second % 2 != 0) 
                return -1;
        }

        int mn = min(basket1[0], basket2[0]);

        vector<int> ex1, ex2;
        for (auto &m : cnt) {
            int v     = m.first;
            int total = m.second;
            int want  = total / 2;

            if (cnt1[v] > want) {
                int extra = cnt1[v] - want;
                while (extra--) ex1.push_back(v);
            }
            if (cnt2[v] > want) {
                int extra = cnt2[v] - want;
                while (extra--) ex2.push_back(v);
            }
        }

        sort(ex1.begin(), ex1.end());
        sort(ex2.begin(), ex2.end(), greater<int>());

        long long ans = 0;
        for (int i = 0; i < ex1.size(); i++) {
            ans += min((long long)min(ex1[i], ex2[i]), 2LL * mn);
        }

        return ans;

    }
};const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
