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