class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> ans;
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i++) 
        {
            for (int j = i + 1; j < n - 1; j++) 
            {
                int num1 = nums[i];
                int num2 = nums[j];

                int pos = lower_bound(nums.begin() + j + 1, nums.end(), target - (num1 + num2)) - nums.begin();
                
                if (pos < n) 
                {
                    int num3_1 = nums[pos];
                    ans.push_back({abs((num1 + num2 + num3_1) - target), num1 + num2 + num3_1});
                }
                if (pos - 1 > j) 
                {
                    int num3_2 = nums[pos - 1];
                    ans.push_back({abs((num1 + num2 + num3_2) - target), num1 + num2 + num3_2});
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans[0].second;
    }
};
