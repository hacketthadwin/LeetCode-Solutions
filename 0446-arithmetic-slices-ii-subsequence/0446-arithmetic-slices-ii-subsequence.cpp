class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
  int n = nums.size();
        vector<unordered_map<long, int>> mp(n); 
        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)nums[i] - nums[j];
                int count_at_j = mp[j][diff]; // Get count of subsequences with the same difference ending at j
                mp[i][diff] += count_at_j + 1; // Update count for i, this is number of subsequence till i
                result += count_at_j; // Only add subsequences of length >= 3 
                //this is ensured because of this
               // https://scribd.com/document/813733676/Problem-Count-Summary
               //if above link don't work then this
               // https://justpaste.it/e7c79
            }
        }
        return result;
    }
};