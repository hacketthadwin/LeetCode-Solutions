class Solution {
public:
    bool f(int m,int r,vector<int>& nums, int target)
    {
        if(((r<nums.size()) && (nums[m]>nums[r])) || (nums[m]>nums.back()))
        {
            return false;
        }
        return true;
    }
    bool check(int m,vector<int>& nums, int target)
    {
        if(nums[m]<target)return false;
        return true;
    }
    int search(vector<int>& nums, int target) {
       //first finding the cut point, so
       //so pattern will be like FFFFFFTTTTTTT
       //so first pattern i.e. first x satisfying f(x)

       int l=-1,r=nums.size()-1,m;
       while(r-l>1)
       {
            m=l+(r-l)/2;
            if(f(m,r,nums,target))
            {
                r=m;
            }
            else
            {
                l=m;
            }
       }
       int val=r;
       //r is the cut point, now the numbers either lie from 0 to l, or from r to nums.size()
        //now just need to search the required number
       if(val>0 && target>=nums[0] && target<=nums[l])
       {
            l=-1,r=val-1;
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
            if(nums[r]==target)return r;
            return -1;
       }
       else
       {
            l=val-1,r=nums.size()-1;
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
            if(nums[r]==target)return r;
            return -1;
       }

    
       
    }
};