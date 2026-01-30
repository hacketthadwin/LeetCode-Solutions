class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>mp;
        mp[0]=1;
        int curr_sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            mp[curr_sum]++;
            ans+=mp[curr_sum-goal];
        }
        if(goal==0)
        {
            return (ans-nums.size());
        }
        return ans;
    }
};