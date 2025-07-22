class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n+1,0);
        prefix[1]=nums[0];
        for(int i=2;i<=n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        unordered_map<int,int>mp;
        int max_sum=0;
        for(int i=0,j=0;j<n && i<n;j++)
        {
            if(!mp.count(nums[j]))
            {
                mp[nums[j]]=j;
            }
            else
            {
                i=max(i,mp[nums[j]]+1);   //ok so the error was in this line
                //i didn't thought that i can also move backwards with this logic and if it moved backwards then multiple elements will get counted, so the score will increase;

                mp[nums[j]]=j;
            }
            max_sum=max(max_sum,prefix[j+1]-prefix[i]);
        }
        return max_sum;
    }
};