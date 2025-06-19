class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
       if(m==1)
       {
            long long ans=LLONG_MIN;
            for(int i=0;i<n;i++)
            {
                ans=max(ans,(long long) nums[i]*nums[i]);
            }
            return ans;
       }
       else
       {
        long long currmax=LLONG_MIN;
        long long curr=0;   
        vector<pair<int,int>>vals(n); 
        vals[0].first=nums[0];
        vals[0].second=nums[0];
            for(int i=1;i<n;i++)
            {
                vals[i].first=max(nums[i],vals[i-1].first);
                vals[i].second=min(nums[i],vals[i-1].second);
            }

        for(int i=m-1;i<n;i++)
        {
            long long num=max((long long)nums[i]*vals[i-m+1].second,(long long)nums[i]*vals[i-m+1].first);
            currmax=max(currmax,num);
        }
        return currmax;
       }
    }
};