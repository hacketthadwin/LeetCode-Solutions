class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el=nums[0];
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==el)
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

        //so el is our potential answer
        cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(el==nums[i])
            {
                cnt++;
            }
        }

        if(cnt>(nums.size()/2))return el;
        return -1;
    }
};