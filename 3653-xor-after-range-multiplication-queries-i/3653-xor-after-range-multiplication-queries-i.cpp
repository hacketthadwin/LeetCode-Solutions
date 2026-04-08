class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      int n=nums.size();
        const int mod=1000000007;
        vector<long long>temp(n);
        for(int i=0;i<n;i++)temp[i]=(long long)nums[i];
    for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];

            for(int j=l;j<=r;j+=k)
                {
                    temp[j]=(temp[j]*v)%(mod);
                }
        }

        int ans=0;
        for(int i=0;i<n;i++)
            {
                ans^=(int)temp[i];
            }

        return ans;
    }
};