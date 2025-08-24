class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int curr_max = 0;
        int n = nums.size();
        int first = -1;
        for (int i = 0; i < n; i++) 
        {
            if (nums[i] == 1) 
            {
                first = i;
                break;
            }
        }
        if (first == -1) return 0;

        for (int i = first; i < n; i++) 
        {
            if (nums[i] == 0) continue;
            int j = i;
            while (j < n && nums[j] == 1) j++;
            int left = j - i;
            int k = j + 1, right = 0;
            while (k < n && nums[k] == 1) 
            {
                right++;
                k++;
            }
            curr_max = max(curr_max, left + right);
            i = j;
        }

        return curr_max == n ? n - 1 : curr_max;
    }
};
