class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)s.insert(nums[i]);
        }
        if(s.empty())
        {
            s.insert(*max_element(nums.begin(),nums.end()));
        }
        vector<int>temp(s.begin(),s.end());
        int ans=accumulate(temp.begin(),temp.end(),0);
        return ans;
    }
};