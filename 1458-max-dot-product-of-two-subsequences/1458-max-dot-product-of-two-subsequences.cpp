class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<vector<int>>dp(502,vector<int>(502,-1e9));
        //i choose state as dp[i][j] where dp[i][j] returns maximum product till i and j
        //now the transition state will look like dp[i][j] = max(dp[i][j],max(dp[i+1][j],dp[i][j+1],dp[i+1][j+1]))
        //this means i select first nums1 current number and move ahead, then  i select nums2 current number and move ahead, then i select both numbers of nums1 and nums2 current number and move ahead
        //now i am confused, i have solved these 2 nums problem before also, but i am forgetting how i did it and i don't want to look at that problem, i want to solve this one with solely my intuition 
        //also i know if i can select same number multiple times i will start my loop from 0 else from n if only once
        //so i am going to start from n
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int taking_both = nums1[i]*nums2[j];
                dp[i][j] = max(dp[i][j],dp[i+1][j]);  //taking nums1 and not taking nums2
                dp[i][j]= max(dp[i][j],dp[i][j+1]);    //taking nums2 and not taking num1
                dp[i][j]= max(dp[i][j],dp[i+1][j+1] + taking_both);   //taking both
                dp[i][j]=max(dp[i][j],taking_both);  //starting a new subsequence (missed this case intially)
            }
        }
        
        return dp[0][0];
    }
};