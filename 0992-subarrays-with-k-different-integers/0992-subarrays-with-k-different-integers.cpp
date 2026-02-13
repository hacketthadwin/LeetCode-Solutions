class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //number of subarrays <=k - number of subarrays <= (k-1)
        map<int,int>mp1,mp2;
        int l=0,r=0,ans=0;
        while(r<nums.size())
        {
            mp1[nums[r]]++;
            while((l<=r) && ((mp1.size())>k))
            {
                mp1[nums[l]]--;
                if(mp1[nums[l]]==0)
                {
                    mp1.erase(nums[l]);
                }
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        l=0;
        r=0;
        int ans1=0;
        while(r<nums.size())
        {
            mp2[nums[r]]++;
            while((l<=r) && ((mp2.size())>(k-1)))
            {
                mp2[nums[l]]--;
                if(mp2[nums[l]]==0)
                {
                    mp2.erase(nums[l]);
                }
                l++;
            }
            ans1+=(r-l+1);

            r++;
        }

        return ans-ans1;
    }
};