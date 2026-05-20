// class Solution {
// public:
// bool is_equal=false;
// bool check(int m,int r,vector<int>& nums)
// {
//     is_equal=false;
//     if(nums[m]>nums[r])
//     {
//         return true;
//     }
//     if(nums[m]==nums[r])
//     {
//         is_equal=true;
//         return false;
//     }
//     return false;
    
// }
// bool f(int m,vector<int>& nums, int target)
// {
//     if(m < 0) return true;
//     if(m >= nums.size()) return false;
//     if(nums[m]<=target)return true;
//     return false;
// }
//     bool search(vector<int>& nums, int target) {
//         //yeah so similar thought process here, what i want to find if the target exists in this nums or not
//         //as it is rotated, so it has 2 parts, first i will have to find the point where it breaks, then from that point i will find the point by finding in which part it exists
//         //so first finding the point
//         //the current number is keeps on increasing and it breaks at a certain point
//         //so first my job will be to find the point where it breaks
//         //for that what can be the pattern, it would be TTTTTFFFF where T denotes if the nums[m]>nums[r]
//         //now since it can be equal also so there will be three pointers, either <,>,==
//         //also as this pattern is finding last true, if my current mid is true, then i will want to go right, for going left, i will do l=mid
//         //and also as this pattern is highest x satisfying f(x), so it will have the numbers as l=0,r=nums.size(),m;
//         //i guess for now this one's correct
//         //as i am shifting l, so l will be my correct answer at last also (also a trick that whatever is in if statement is correct answer)
//         //also my edge case will be if r is nums.size(), i cannot compare the nums[r] because it will throw error, how do i tackle it
//         //i will do 
//         // int l=0,r=nums.size(),m;
//         //NOTE : THIS IS DIFFERENT FROM NORMAL BINARY SEARCH PROBLEMS THAT'S WHY I AM HAVING DIFFICULTY, IN NORMAL BS, WE DON'T TAKE r INTO CONSIDERATION HENCE, WE WRITE r=highest_possible_value+1, BUT SINCE HERE WE TOOK r IN CONSIDERATION, SO IT WILL BE r=nums.size()-1 AND FOR COUNTERING THAT, WE TAKE ONE STEP BEHIND AS VIRTUAL BOUNDARY l=-1. BUT THIS IS ONLY FOR THIS PROBLEM
        
//         int l=-1,r=nums.size()-1,m;
//         while(r-l>1)
//         {
//             m=l+(r-l)/2;
//             if(check(m,r,nums))
//             {
//                 l=m;
//             }
//             else
//             {
//                 if(!is_equal)
//                 {
//                     r=m;
//                 }
//                 else
//                 {
//                     is_equal=false;
//                     r--;
//                 }

//             }
//         }

//         //l is my last highest number, like including all its equal values too, r is the point from where second line starts
//         int val=r;
//         //so my first check will be from 0 to l, then second can be from r to nums.size()

//         //then for searching, i have been given limits of array, i have been given target, i just have to find target
//         //this is problem of finding target now, so how do we find target in array, we just do typically binary_search() function, but i want to do manually, so if nums[m]<=target, move right, else move left
//         //so my pattern would be TTTTTFFFFF and the last T will be my answer, so again this problem is of finding highest x satisfying f(x) and if my current mid is true, then i will want to go right, that is l=mid
//         if(val<=0 || target>=nums[0] && target<=nums[val-1])
//         {
//             l=-1,r=val;
//             while(r-l>1)
//             {
//                 m=l+(r-l)/2;
//                 if(f(m,nums,target))
//                 {
//                     l=m;
//                 }
//                 else
//                 {
//                     r=m;
//                 }
//             }

//             //then the final l will be my answer, so
//             if(l>=0 && nums[l]==target)return true;
//             return false;

//         }
//         else
//         {
//             l=val-1,r=nums.size();
//             while(r-l>1)
//             {
//                 m=l+(r-l)/2;
//                 if(f(m,nums,target))
//                 {
//                     l=m;
//                 }
//                 else
//                 {
//                     r=m;
//                 }
//             }

//             //then the final l will be my answer, so
//             if(nums[l]==target)return true;
//             return false;

//         }
//     }
// };

class Solution {
public:

bool is_equal=false;
bool is_equal_2=false;

bool check(int m,int r,vector<int>& nums)
{
    if(nums[m]>nums[r])
    {
        return true;
    }

    return false;
    
}

bool f(int m,vector<int>& nums, int target)
{
    //virtual true boundary
    if(m < 0) return true;

    //virtual false boundary
    if(m >= nums.size()) return false;

    //equal handled separately because equality destroys clean TTTTFFFF partition
    if(nums[m]==target)
    {
        is_equal_2=true;
        return false;
    }

    //changed <= to < because now pattern becomes proper TTTTFFFF
    if(nums[m]<target)return true;

    return false;
}

    bool search(vector<int>& nums, int target) {

        //so first thing i need to do is reset my global variables because leetcode creates one object and uses it for all test cases, so old true values will carry over and ruin my logic
        is_equal=false;
        is_equal_2=false;

        //yeah so similar thought process here, what i want to find if the target exists in this nums or not

        //as it is rotated, so it has 2 parts, first i will have to find the point where it breaks, then from that point i will find the point by finding in which part it exists

        //so first finding the point

        //the current number is keeps on increasing and it breaks at a certain point

        //so first my job will be to find the point where it breaks

        //for that what can be the pattern, it would be TTTTTFFFF where T denotes if the nums[m]>nums[r]

        //now since it can be equal also so there will be three pointers, either <,>,==

        //also as this pattern is finding last true, if my current mid is true, then i will want to go right, for going right, i will do l=mid

        //NOTE : THIS IS DIFFERENT FROM NORMAL BINARY SEARCH PROBLEMS THAT'S WHY I AM HAVING DIFFICULTY, IN NORMAL BS, WE DON'T TAKE r INTO CONSIDERATION HENCE, WE WRITE r=highest_possible_value+1, BUT SINCE HERE WE TOOK r IN CONSIDERATION, SO IT WILL BE r=nums.size()-1 AND FOR COUNTERING THAT, WE TAKE ONE STEP BEHIND AS VIRTUAL BOUNDARY l=-1. BUT THIS IS ONLY FOR THIS PROBLEM
        
        int l=-1,r=nums.size()-1,m;

        while(r-l>1)
        {
            m=l+(r-l)/2;

            //duplicates destroy monotonicity, cannot infer side safely
            if(nums[m]==nums[r])
            {
                //if the current r is exactly the point where the drop happens, doing r-- blindly will skip the pivot entirely!
                //the drop point is the ONLY place where the previous number is greater than current number
                if(r - 1 >= 0 && nums[r-1] > nums[r])
                {
                    //we found the exact break point, so we bring l right behind r to terminate the loop perfectly
                    l = r - 1; 
                }
                else
                {
                    r--;
                }
            }
            else if(check(m,r,nums))
            {
                l=m;
            }
            else
            {
                r=m;
            }
        }

        //pivot is first false
        int val=r;

        //left half is [0...val-1]
        //right half is [val...n-1]

        //then for searching, i have been given limits of array, i have been given target, i just have to find target

        //this is problem of finding target now

        //pattern becomes TTTTFFFF where T means nums[m]<target

        //i changed val==0 to val>0 here because if val is 0 then array is not rotated at all like [1,2,3], so if i keep it val==0 it will just search from -1 to 0 and fail, so i want it to go to else block to search whole array limits
        if(val>0 && (target>=nums[0] && target<=nums[val-1]))
        {
            //virtual true
            l=-1;

            //virtual false
            r=val;

            while(r-l>1)
            {
                m=l+(r-l)/2;

                is_equal_2=false;

                if(f(m,nums,target))
                {
                    l=m;
                }
                else
                {
                    //equal handled separately
                    if(is_equal_2)return true;

                    r=m;
                }
            }

            if((r<nums.size())&&(nums[r]==target))return true;

            return false;

        }
        else
        {
            //virtual true
            l=val-1;

            //virtual false
            r=nums.size();

            while(r-l>1)
            {
                m=l+(r-l)/2;

                is_equal_2=false;

                if(f(m,nums,target))
                {
                    l=m;
                }
                else
                {
                    //equal handled separately
                    if(is_equal_2)return true;

                    r=m;
                }
            }

            if((r<nums.size())&&(nums[r]==target))return true;

            return false;
        }
    }
};