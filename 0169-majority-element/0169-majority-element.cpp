class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //so this is moore's voting algorithm problem
        int cnt=0;
        int el=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(el==nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if(cnt==0)
            {
                if(i+1<nums.size())
                {
                    el=nums[i+1];
                    cnt=0;
                }
            }
        }
        cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(el==nums[i])
            {
                cnt++;
            }
        }
        if(cnt>(nums.size()/2))
        {
            return el;
        }
        return -1;
    }
};