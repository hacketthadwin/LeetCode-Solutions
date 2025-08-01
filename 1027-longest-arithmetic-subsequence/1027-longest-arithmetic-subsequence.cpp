class Solution {
public:
    int dp[1000][1000];

    int longestArithSeqLength(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return n;
        unordered_map<int, vector<int>> pos;
        pos.reserve(n * 2);
        for (int i = 0; i < n; ++i) {
            pos[arr[i]].push_back(i);
        }
        for (auto& [v, vec] : pos) {
            sort(vec.begin(), vec.end());
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = 2;

        int ans = 2;
        for (int prev = n - 2; prev >= 0; --prev) {
            for (int curr = prev + 1; curr < n; ++curr) {
                int diff = arr[curr] - arr[prev];
                int want = arr[curr] + diff;
                auto it = pos.find(want);
                if (it != pos.end()) {
                    const vector<int>& indices = it->second;
                    auto itr = lower_bound(indices.begin(), indices.end(), curr + 1);
                    if (itr != indices.end()) {
                        int next = *itr;
                        dp[prev][curr] = max(dp[prev][curr], dp[curr][next] + 1);
                    }
                }
                ans = max(ans, dp[prev][curr]);
            }
        }
        return ans;
    }
};

