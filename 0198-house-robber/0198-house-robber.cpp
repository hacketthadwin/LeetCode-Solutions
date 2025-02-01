class Solution {
    //the bottom up approach of this code is very strange, common, but difficult to understand
public:
    int rob(vector<int>& nums) {
        //this literal just like O(1) code, technically O(n) but n=100, so does it matter?
        vector<int>t(nums.size()+1,0);
        //t[i] denotes maximum money till ith house
        t[1]=nums[0];
        for(int i=2;i<=nums.size();i++)
        {
            //stealing from current house and checking the maximum value till (i-2)th house, because we cannot check from (i-1)th house
            int steal=nums[i-1]+t[i-2];
            //same for skip, choosing the last house value only,thus skipping current house value
            int skip=t[i-1];

            //choosing maximum value till now
            t[i]=max(steal,skip);
        }
        return t[nums.size()];
    }
};