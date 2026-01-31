class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //using the same approach as Binary Subarrays With Sum
        //now what we will do here is first we will count number of subarrays with odd count<=k
        //then we will find number of subarrays with odd count <= k-1
        //then we will subtract second one from first one
        int l=0,r=0,ans=0;
        int curr_cnt=0;
        while(r<nums.size())
        {
            //before shrinking do your task of adding the numbers
            if(nums[r]%2==1)
            {
                curr_cnt++;
            }

            while((l<=r) && (curr_cnt>k))
            {
                if(nums[l]%2==1)
                {
                    curr_cnt--;
                }
                l++;
            }

            ans+=(r-l+1);
            r++;
        }

         l=0,r=0;
         int ans1=0;
         curr_cnt=0;
        while(r<nums.size())
        {
            //before shrinking do your task of adding the numbers
            if(nums[r]%2==1)
            {
                curr_cnt++;
            }

            while((l<=r) && (curr_cnt>(k-1)))
            {
                if(nums[l]%2==1)
                {
                    curr_cnt--;
                }
                l++;
            }

            ans1+=(r-l+1);
            r++;
        }

        return ans-ans1;
    }
};