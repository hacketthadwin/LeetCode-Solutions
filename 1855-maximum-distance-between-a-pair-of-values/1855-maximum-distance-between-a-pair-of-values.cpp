class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        //i have been given two non increasing nums, what the hell, this one's too easy
        // reverse(nums1.begin(),nums1.end());
        // reverse(nums2.begin(),nums2.end());
        // //now the numbers that i want to find became n-i-1 and m-j-1, i want to find difference of these 2
        // //i want nums2 value to be bigger than mine, hence i will do just lower bound in num2 to find the first value which is bigger than nums1 and then if there is any number, i will directly take the last index
        // for(int i=0;i<nums1.size();i++)
        // {

        // }

        //but this can be simply solved using two pointers as
        int maxi=0;
        for(int i=0,j=0;i<nums1.size() && j<nums2.size();)
        {
            if(nums1[i]<=nums2[j])
            {
                // if(j>=i)maxi=max(j-i,maxi);   //update the value before increment, else will get redundant value
                j++;
            }
            else
            {
               if(i<j)
               {
                     i++;
               }
               else
               {
                    i++;
                    j++;
               }
            }
            if(j>=i)maxi=max(j-i,maxi); //here also works, but just needs a bit modification in the return value because 
            
        }
        if(maxi==0)
        {
            return 0;
        }
        else
        {
            return maxi-1;
        }
    }
};