class Solution {
public:
    vector<string>arr;
    int solve(string currstring,int idx)
    {
        //pruningcase
        map<char,int>mp;
        for(int k=0;k<currstring.size();k++)
        {
            if(mp[currstring[k]])return 0;
            else mp[currstring[k]]++;
        }
       //basecase
       if(idx==arr.size())return currstring.size();
       //compute and transition
        int maxResult = currstring.size();
        for (int i = idx; i < arr.size(); i++) 
        {
            maxResult = max(maxResult, solve(currstring + arr[i], i + 1));
        }

        return maxResult;

    }
    int maxLength(vector<string>& arr1) {
        arr=arr1;
        int ans=solve("",0);
        return ans;
        
    }
};