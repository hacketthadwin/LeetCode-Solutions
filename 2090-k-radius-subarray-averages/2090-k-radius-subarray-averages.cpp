class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long int n=nums.size();
        vector<long long int> prefix(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }
        vector<int> ans(n,-1);
        for(int i=k;i<n-k;i++)
        {
            ans[i]=(prefix[i+k+1]-prefix[i-k])/((2*k)+1);
        }
        return ans;
        
    }
};