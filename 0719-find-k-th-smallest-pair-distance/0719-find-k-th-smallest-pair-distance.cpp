class Solution {
public:
// this problem involves both two pointers and binary search algorithm, the check function is two pointers function of type 2 and the main function is binary search
//this is one of the best problem to practice for both algorithm
    bool check(long long mid,vector<int>& nums, int k )
    {
        int count = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            while (j < nums.size() && nums[j] - nums[i] <= mid) {
                j++;
            }
            count += (j - i - 1);
        }
        return count >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
       long long int lo=0;
        long long int hi=1e7;
        long long int mid;
        while((hi-lo)>0)
        {
            mid=(lo+hi)/2;
            if(check(mid,nums,k))
            {
                hi=mid;
            }
            else
            {
                lo=mid+1;
            }
        }
        return lo;
        
    }
};