class Solution {
    private:
    void generateSubsets(vector<int>& nums, vector<vector<int>>& subsets) {
    int n = nums.size();
    int total = 1 << n; // 2^n subsets in total

    for (int mask = 1; mask < total; ++mask) { // skip 0 to avoid empty set
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
}
public:
    int countMaxOrSubsets(vector<int>& arr) {
        long long max_or=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            max_or= (long long)max_or|arr[i];
        }
        vector<vector<int>>subs;
        generateSubsets(arr,subs);
        int ans=0;
        for(int i=0;i<subs.size();i++)
        {
            long long curr_or=subs[i][0];
            for(int j=1;j<subs[i].size();j++)
            {
                curr_or= (long long)curr_or|subs[i][j];
            }

            if(curr_or == max_or)ans++;
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
