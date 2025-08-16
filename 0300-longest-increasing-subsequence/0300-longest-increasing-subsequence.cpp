class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> lis;
        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(lis.begin(),lis.end(),arr[i]);
            if(it==lis.end())//the current element is greater than last element
            {
                lis.push_back(arr[i]);
            }
            else
            {
                lis[(it-lis.begin())]=arr[i]; //replace the element
            }
        }

        return lis.size();
    }
};