class Solution {
public:
//so the technique is first find the length of longest subsequence and then find the count of the subsequence...so its not that tough
vector<int>dp1;
vector<int>dp2;
// vector<int>dp3;
    int rec(int idx,vector<int>& nums)
    {
        //base case
        if(idx==nums.size())
        {
            return 0;
        }
        if(dp1[idx]!=-1)return dp1[idx];
        int cnt=1;
        for(int i=idx+1;i<nums.size();i++)
        {
            if(nums[i]>nums[idx])
            {
               cnt=max(cnt,1+rec(i,nums));
               
            }
        }

        return dp1[idx]=cnt;

    }
    int len_longest;
    int rec2(int idx,vector<int>& nums)
    {
        if(dp1[idx]==1)return 1;
        // if(idx==nums.size())
        // {
        //     return 0;
        // }
        if(dp2[idx]!=-1)return dp2[idx];
        //compute and transition
        int cnt=0;
        for(int i=idx+1;i<nums.size();i++)
        {
            if(dp1[i]==dp1[idx]-1 && nums[i]>nums[idx])
            {
                cnt+=rec2(i,nums);
            }
        }
        return dp2[idx]=cnt;
        
    }
    int findNumberOfLIS(vector<int>& nums) {
        dp1.resize(nums.size()+5,-1);
        dp2.resize(nums.size()+5,-1);
        for(int i=0;i<nums.size();i++)len_longest=max(rec(i,nums),len_longest);

       int cnt=0;
       for(int i=0;i<nums.size();i++)
       {
            if(dp1[i]==len_longest)cnt+=(rec2(i,nums));
       }
        return cnt;
    }
};