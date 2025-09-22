class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int count[101]={0};
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
        int min=-1;
        for(int i=0;i<=100;i++)
        {
            if(count[i]>min)
            {
                min=count[i];
            }
        }
        int ans=0;
        for(int i=0;i<=100;i++)
        {
            if(count[i]==min)
            {
                ans+=count[i];
            }
        }

        return ans;

        
    }
};