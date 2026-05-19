class Solution {
public:
    // bool found
    bool check(int m,vector<int>& nums, int target)
    {
        if(nums[m]>target)
        {
            return true;
        }
        return false;
    }
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size(),m;
        while(r-l>1)
        {
            m=l+(r-l)/2;
            if(check(m,nums,target))
            {
                r=m;
            }
            else
            {
                l=m;
            }
        }
        if(nums[l]==target)return l;
        return -1;
    }
};