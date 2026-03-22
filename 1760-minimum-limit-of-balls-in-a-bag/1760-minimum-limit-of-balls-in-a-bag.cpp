class Solution {
public:
    bool f(int m, vector<int>& nums, int maxOperations)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=m)continue;
                if(maxOperations>0)
                {
                    // maxOperations --;
                    //now i was thinking that any number can get divided multiple parts in just operation but it's not because what if nums[i]=9 and m=3
                    //then it will be 3+3+3, it means 2 operations, so 3 parts = 2 operations
                    //so for n parts, it will be n-1 operations
                    //now in how many parts will our number be divided = ceil(nums[i]/m);
                    //NOTE:CEIL FUNCTION ONLY WOKRS ON FLOATING POINT NUMBERS, NOT INT, SO FOR INT, WE USE THIS FORMULA BELOW
                    //(x+m-1)/m gives ceil of 2 int numbers x and m i.e. x/m
                    if(maxOperations<(((nums[i]+m-1)/m))-1)
                    {
                        return false;
                    }
                    maxOperations -= (((nums[i]+m-1)/m)-1);
                    //the below is another way of writing the same thing
                    // if(maxOperations<(((nums[i]-1)/m)))
                    // {
                    //     return false;
                    // }
                    // maxOperations -= (((nums[i]-1)/m));
                }
                else
                {
                    return false;
                }
            
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=0,r=INT_MAX;
        //here m denotes the penalty, which is maximum number of balls after division
        while((r-l)>1)
        {
            int m=(l+(r-l)/2);
            if(f(m,nums,maxOperations))
            {
                r=m;
            }
            else
            {
                l=m;
            }
        }
        return r;
    }
};