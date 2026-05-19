class Solution {
public:

bool check(int m,vector<int>& nums, int target)
{
    if(nums[m]<target)
    {
        return true;
    }
    return false;
}
    int searchInsert(vector<int>& nums, int target) {
        int l=-1,r=nums.size(),m;
        while(r-l>1)
        {
            m=l+(r-l)/2;
            if(check(m,nums,target))
            {
                l=m;
            }
            else
            {
                r=m;
            }
        }
        return r;
    }
};