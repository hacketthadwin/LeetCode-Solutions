class Solution {
public:
    bool check(long long int mid,vector<int> arr, int m, int k)
    {
        //in this problem we don't need to have currsum variable because we are checking maximum days and we are not summing consecutive days
       long long currk=0;
       long long currm=0;
       for(int i=0;i<arr.size();i++)
       {
           
            if(arr[i]<=mid)
            {
                currk++;
                if(currk>=k)
                {
                    currk=0;
                    currm++;
                }
            }
            else
            {
                currk=0;
                
            }
            if(currm>=m)return 0;
       }
       return 1;
    }
    long long int minDays(vector<int>& arr, int m, int k) {
    long long int lo=0;
    long long int hi=1e16;
    long long int mid;
    long long int ans=LLONG_MAX;
    if ((long long)m * k > arr.size()) return -1;
    while((hi-lo)>1)
    {
        mid=lo+(hi-lo)/2;
        if(check(mid,arr,m,k))
        {
            lo=mid;
        }
        else
        {
            ans=min(ans,mid);
            hi=mid;   
        }
        
    }
        return ans;
    }
};