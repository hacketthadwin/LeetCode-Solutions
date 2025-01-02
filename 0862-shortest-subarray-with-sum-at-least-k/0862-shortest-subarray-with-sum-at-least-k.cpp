class Solution {
public:

//this looks like type 2 problem of 2 pointers but is not i tried solving it but it gave wrong answer
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int>dq;
        int ans=INT_MAX;
        vector<long long> prefixsum(nums.size() + 1, 0);   //mistake: didn't calculated prefix sum
        for(int i=0;i<nums.size();i++)
        {
            prefixsum[i+1]=prefixsum[i]+nums[i];
        }
        
        for(int i=0;i<prefixsum.size();i++)
        {
            while(!dq.empty() && prefixsum[i]-prefixsum[dq.front()]>=k)
            {
                ans=min(ans,i-dq.front());    // mistake: did i-dq.front()+1 
                dq.pop_front();
            }   
            while(!dq.empty() && prefixsum[dq.back()]>prefixsum[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans==INT_MAX? -1 : ans;
        
    }
};