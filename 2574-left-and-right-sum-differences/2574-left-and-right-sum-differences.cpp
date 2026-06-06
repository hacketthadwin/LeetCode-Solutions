class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>left_sum(nums.size(),0);
        for(int i=1;i<nums.size();i++)
        {
            left_sum[i]=left_sum[i-1]+nums[i-1];
        }
        vector<int>right_sum(nums.size(),0);
        for(int i=nums.size()-2;i>=0;i--)
        {
            right_sum[i]=right_sum[i+1]+nums[i+1];
        }

        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=abs(right_sum[i]-left_sum[i]);
        }
        return ans;
    }
};