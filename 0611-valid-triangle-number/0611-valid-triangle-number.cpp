class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //so i have 2 numbers, nums[i] and nums[j] which are 2 different elements
                //now i need to find lower_bound(nums[i]+nums[j]) and then number of elements
                int num1=nums[i];
                int num2=nums[j];
                auto it = lower_bound(nums.begin()+j+1,nums.end(),num1+num2);
                int idx =it-nums.begin();
                ans +=(idx-(j+1));
            }
        }

        return ans;
    }
};