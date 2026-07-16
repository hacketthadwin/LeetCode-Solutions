class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>pre_gcd(nums.size());
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);
            pre_gcd[i]=__gcd(nums[i],maxi);
        }
        sort(pre_gcd.begin(),pre_gcd.end());
        vector<int>pair_gcd;
        long long sum=0;
        for(int i=0;i<pre_gcd.size()/2;i++)
        {
            int a=pre_gcd[i];
            int b=pre_gcd[nums.size()-1-i];
            sum+=(long long)(__gcd(a,b));
        }
        return sum;


    }
};