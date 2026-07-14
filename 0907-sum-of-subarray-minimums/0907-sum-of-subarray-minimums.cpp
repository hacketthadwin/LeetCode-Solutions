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
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>prev=prev_smaller(arr);
        vector<int>next=next_smaller(arr);
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            int l=prev[i];
            int r=next[i];
            ans=(ans+(((long long)((arr[i]*(i-l))%mod)*(r-i))%mod))%mod;
        }
        return ans;
    }
};
// class Solution {
// public:
// //now a tip i got..that in these subarrays types problem one approach is monotonic stack or deque also...
// //but keep in mind that we take contribution of each element in answer instead of building answer
//     int sumSubarrayMins(vector<int>& arr) {
//         int l=0;
//         deque<int>min_dq,max_dq;
//         //max_dq means increasing dq..so for that pop back every element which is less than current element of arr
//         //min dq means decreasing dq...so for that pop back every element which is more than current element of arr
//         //though i don't need the max_dq here....but just for sake of revision
//         for(int r=0;r<arr.size();r++)
//         {
//             //make both min and max dq respectively
//             // while(!max_dq.empty() && arr[max_dq.back()]<=arr[r])
//             // {
//             //     max_dq.pop_back();
//             // }

//             // max_dq.push_back(i);

//             while(!min_dq.empty() && arr[min_dq.back()]>=arr[r])
//             {
//                 min_dq.pop_back();
//             }

//             min_dq.push_back(i);

//             //now pop front the element which are not valid

//             while(!min_dq.empty() && min_dq.front()<l)
//             {
//                 min_dq.pop_back();
//             }

//             //now current window is valid

//             //arr[dq.back()] will give you minimum in that range

            


            
//         }
//     }
// };