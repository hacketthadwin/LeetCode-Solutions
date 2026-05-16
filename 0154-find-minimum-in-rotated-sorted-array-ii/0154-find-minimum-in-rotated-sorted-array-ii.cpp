class Solution {
public:
bool is_equal=false;
bool check(int m,int r,vector<int>& nums)
{
    is_equal = false;
    if(nums[m]<nums[r])
    {
        return false;
    }
    if(nums[m]==nums[r])
    {
        is_equal=true;
        return false;
    }
    return true;
}
    int findMin(vector<int>& nums) {
        //this problem is very different from the normal binary search problems i solve(we solve), because in general binary search we have 2 states, either true or false, but in this binary search we have 3 states
        //less than, more than, equals to . these are the three states we have, and when the nums[m]==nums[r], we can't move much furthur by doing r=m, so we have to move by just one place r-- and that's why problem also mentioned "You must decrease the overall operation steps as much as possible"
        if(nums[0]<nums.back())return nums[0];
        int l=-1,r=nums.size()-1,m;
        // int ans=INT_MAX;
        while(r-l>1)
        {
            m=l+(r-l)/2;
            if(check(m,r,nums))
            {
                l=m;
            }
            else
            {
                if(!is_equal)
                {
                    r=m;
                }
                else
                {
                    r--;
                }
                
            }
        }
        return nums[r];
    }
};