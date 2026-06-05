class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        //so i need to find like a multiplication table..infact...i can store it..because the constraint are low...
        //so i can store the multiplication table of each number from 0 to 1e5...then all i got to do is find sum of their..nah man...but nums got negative numbers too..i cannot take..negative number as index...but who said anything about map...
        int first_val=0;
        int total_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            //nums[i] is the number...i is the multiplication
            //i want multiplication of nums[i] with every i from 0 to nums.size()-1
            first_val+=i*(nums[i]);
            total_sum+=(nums[i]);
        }
        int max_ans=first_val;
        int n=nums.size();
        for(int i=1;i<nums.size();i++)
        {
            int temp=first_val+total_sum-n*(nums[n-i]);
            max_ans=max(max_ans,temp);
            first_val=temp;
        }
        return max_ans;
    }
};