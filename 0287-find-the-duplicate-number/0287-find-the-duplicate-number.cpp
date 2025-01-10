class Solution {
public:
//so i could not solve this problem and the approach of this problem is pretty easy, we have been given that there is an array which should contains element from 1 to n,but there is a number which is repeated more than once, and we need to find that number,
//i will find the mid and for original array, we should have number of elements less than equals to mid in the first half 
//because obviously if i have elements 1 2 3 4 5
//my mid is 3, so number of elements less than mid is 1,2,3 (so 3 elements)
//for any permutation we will have (number of elements less than mid) will be less than mid
//so for this case i will increase my mid
//but if i get number of elements less than mid more than mid, the number lies before it
//so in this case i will decrease the mid
bool check(int mid,vector<int>& nums)
{
        int count = 0;
        for (int i = 0; i < nums.size(); i++) 
        {

            if (nums[i] <= mid) count++;
        }
        return count > mid;
}
    int findDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
 long long  int lo = 1, hi = n, mid; // Set the range for binary search
        
        while ((hi-lo)>0) 
        {
            mid = lo + (hi - lo) / 2;
            if (check(mid, nums)) 
            {
                hi = mid; 
            } else 
            {
                lo = mid+1;  
            }
        }
        
        return lo;  
    }
};