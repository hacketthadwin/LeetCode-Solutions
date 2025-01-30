class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool ispossible=true;
        bool ischanged=false;
        vector<int>nums2=nums;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                nums[i]=nums[i+1];
                ischanged=true;
                break;
            }
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                ispossible=false;
            }
        }
        if(ispossible)return true;
        nums=nums2;
        ispossible=true;
        ischanged=false;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                nums[i+1]=nums[i];
                ischanged=true;
                break;
            }
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                ispossible=false;
            }
        }
        if(ispossible)return true;
        return false;





        
    }
};