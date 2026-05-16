# One tip to solve this problem

tip: try to compare current number with last number of nums

also solve the find minimum in rotated sorted array II because it is similar but with one tweak that is nums element can be equal to and that tweak is very hard to observe and very different than normal binary search problems

# Code
```cpp []
class Solution {
public:
bool check(int m,vector<int>& nums)
{
    if(nums[m]<=nums.back())
    {
        return false;
    }
    return true;
}
    int findMin(vector<int>& nums) {
        int l=-1,r=nums.size(),m;
        while(r-l>1)
        {
            m=l+(r-l)/2;
            if(check(m,nums))
            {
                l=m;
            }
            else
            {
                r=m;
            }
        }
        return nums[r];
    }
};
```