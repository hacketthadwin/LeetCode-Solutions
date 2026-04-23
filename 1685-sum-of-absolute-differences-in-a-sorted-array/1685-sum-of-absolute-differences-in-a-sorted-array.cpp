class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>ans(nums.size());
            vector<int>prefix(nums.size(),0);
            prefix[0]=nums[0];
            for(int i=1;i<nums.size();i++)
            {
                prefix[i]= prefix[i-1] + nums[i];
            }
            for(int i=0;i<nums.size();i++)
            {

                ans[i] = ((prefix[nums.size()-1]-prefix[i])-((int)((nums.size()-i-1)*nums[i]))) + (((int)((i+1)*nums[i]))-(prefix[i])); 
            }
            return ans;
    }
};