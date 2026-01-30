class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //in this problem what we will do is first we will count the number of subarrays whose sum is less than equals to k
        //then from that we will subtract the number of subarrays whose sum is less than equals to k-1 or less than k
        //by this way we will get the number of subarrays whose sum is equals to k
        // int l=0,r=0,ans=0;
        // int curr_sum=0;
        // while(r<nums.size())
        // {
        //     if((curr_sum+nums[r])<=k)
        //     {
        //         curr_sum+=nums[r];
        //         ans++;
        //     }

        //     while(l<=r && curr_sum>k)
        //     {
        //         curr_sum-=nums[l];
        //         l++;
        //     }
        //     r++;
        // }

        //  l=0,r=0;
        //  int ans1=0;
        //  curr_sum=0;
        //  int c=k-1;
        // while(r<nums.size())
        // {
        //     if((curr_sum+nums[r])<=c)
        //     {
        //         curr_sum+=nums[r];
        //         ans1++;
        //     }

        //     while(l<=r && curr_sum>c)
        //     {
        //         curr_sum-=nums[l];
        //         l++;
        //     }
        //     r++;
        // }

        // return (ans-ans1);

        //i think i made some error in the implementation part
        //i later saw the video of striver, he implemented this problem in a different and beautiful manner
        //it used to save the unique prefix sum and their counts at a particular index and then check if it is possible to make the desired value (here k), consider the sum till now is s, and if i can make s-k using the previous elements, then i can make k (i.e. one subarray)
        //this approach is non intuitive and requires to understand the solution atleast once to understand

        map<int,int>mp;
        mp[0]=1;
        int curr_sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            mp[curr_sum]++;
            ans+=mp[curr_sum-k];
        }
        if(k==0)
        {
            return (ans-nums.size());
        }
        return ans;

    }
};