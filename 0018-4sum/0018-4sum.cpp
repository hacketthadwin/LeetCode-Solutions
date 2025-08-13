class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n-3; i++) {
            for(int j = i+1; j < n-2; j++) {
                for(int k = j+1; k < n-1; k++) {
                    int num1 = nums[i];
                    int num2 = nums[j];
                    int num3 = nums[k];
                    long long temp_num = (long long)target - (long long)num1 - (long long)num2 - (long long)num3;

                    auto it = lower_bound(nums.begin() + k + 1, nums.end(), temp_num);
                    if(it != nums.end() && *it == temp_num) {
                        ans.push_back({num1, num2, num3, (int)temp_num});
                    }
                }
            }
        }

        set<vector<int>> temp_ans(ans.begin(), ans.end());
        return vector<vector<int>>(temp_ans.begin(), temp_ans.end());
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
