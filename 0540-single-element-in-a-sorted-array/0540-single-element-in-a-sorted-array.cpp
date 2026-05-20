class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //so it is easy, all we need is count, if left side count is odd and right side is even, go towards left
        //else go towards right (one of the side is surely odd)
        //keep going when you reach just return
        //i can't think of predicate function here, so let's go with little discomfort and solve using old way
        int l=0,r=nums.size()-1,m;
        while(r>=l)
        {
            int m=l+(r-l)/2;
            bool match_left = (m > 0 && nums[m] == nums[m - 1]);
            bool match_right = (m < nums.size() - 1 && nums[m] == nums[m + 1]);

            if(!match_left && !match_right) {
                return nums[m];
            }
            if(((m>0) && (nums[m]==nums[m-1]) && ((m-1)%2==1)) || ((m<nums.size()-1) && (nums[m]==nums[m+1]) && ((m%2)==1)))
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return nums[r];
    }
};


