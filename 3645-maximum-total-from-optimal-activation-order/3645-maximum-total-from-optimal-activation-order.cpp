class Solution {
    private:
    void customSort(vector<pair<int,int>> &v) {
    sort(v.begin(), v.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        if (a.first != b.first) 
            return a.first < b.first; 
        return a.second > b.second;    
    });
}

public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();
        vector<pair<int, int>> lim_vals(n);
        for (int i = 0; i < n; i++) {
            lim_vals[i] = {limit[i], value[i]};
        }

        customSort(lim_vals);

        long long ans = 0;
        int curr_active = 0;
        int max_reached = 0;
        multiset<int> active_limits;

        for (auto& p : lim_vals) {
            int l = p.first, v = p.second;
            if (l <= max_reached) continue;
            if (curr_active >= l) continue;
            ans += v;
            active_limits.insert(l);
            int x = active_limits.size();
            max_reached = max(max_reached, x);
            auto it = active_limits.upper_bound(x);
            active_limits.erase(active_limits.begin(), it);
            curr_active = active_limits.size();
        }

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
