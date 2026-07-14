class Solution {
public:
const int mod=1e9+7;
vector<int>prev_smaller(vector<int>arr)
{
    deque<int>dq;
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++)
    {
        while(!dq.empty() && arr[dq.back()]>=arr[i])
        {
            dq.pop_back();   
        }
        if(!dq.empty())ans[i]=dq.back();
        dq.push_back(i);
    }
    return ans;
}
vector<int>next_smaller(vector<int>arr)
{
    deque<int>dq;
    vector<int>ans(arr.size(),arr.size());
    for(int i=arr.size()-1;i>=0;i--)
    {
        while(!dq.empty() && arr[dq.back()]>arr[i])
        {
            dq.pop_back();   
        }
        if(!dq.empty())ans[i]=dq.back();
        dq.push_back(i);
    }
    return ans;
}
vector<int>prev_greater(vector<int>arr)
{
    deque<int>dq;
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++)
    {
        while(!dq.empty() && arr[dq.back()]<=arr[i])
        {
            dq.pop_back();   
        }
        if(!dq.empty())ans[i]=dq.back();
        dq.push_back(i);
    }
    return ans;
}
vector<int>next_greater(vector<int>arr)
{
    deque<int>dq;
    vector<int>ans(arr.size(),arr.size());
    for(int i=arr.size()-1;i>=0;i--)
    {
        while(!dq.empty() && arr[dq.back()]<arr[i])
        {
            dq.pop_back();   
        }
        if(!dq.empty())ans[i]=dq.back();
        dq.push_back(i);
    }
    return ans;
}
    long long subArrayRanges(vector<int>& arr) {
      //now this problem is also similar to the last one
      //i can find next greater element..prev greater element...next smaller element...prev smaller element..
      //and then for each index i can do ans+=(next greater element - curr)*arr[i]*(i-prev greater element) and ans-=(next smaller element - curr)*arr[i]*(i-prev smaller element)
        vector<int>prev_s=prev_smaller(arr);
        vector<int>next_s=next_smaller(arr);
        vector<int>prev_g=prev_greater(arr);
        vector<int>next_g=next_greater(arr);
        long long ans=0;
        for(int i=0;i<arr.size();i++)
        {
            int ls=prev_s[i];
            int rs=next_s[i];
            int lg=prev_g[i];
            int rg=next_g[i];
            ans+=(long long)(((long long)(rg-i)*(i-lg)*arr[i])-((long long)(rs-i)*(i-ls)*arr[i]));
        }
        return ans;
    

        
    }
};

  // deque<int>dq;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(dq.empty())
        //     {
        //         dq.push(i);
        //     }

        //     if(nums[i]>nums[dq.back()])
        //     {
        //         dq.push_back(i);
        //     }
        //     else
        //     {
        //         dq.push_front(i);
        //     }
        // }

        // int ans=0;
        // for(int i=0;i<dq.size();)