class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false;

        for (int start = 0; start <= n - 2 * k; start++) {
            bool first_ok = true;
            bool second_ok = true;

            for (int i = start + 1; i < start + k; i++) {
                if (nums[i] <= nums[i - 1]) {
                    first_ok = false;
                    break;
                }
            }

            for (int i = start + k + 1; i < start + 2 * k; i++) {
                if (nums[i] <= nums[i - 1]) {
                    second_ok = false;
                    break;
                }
            }

            if (first_ok && second_ok) return true;
        }

        return false;
    }
};
