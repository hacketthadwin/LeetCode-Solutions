class Solution {
public:
    vector<string>ans;
    void rec(string&curr,int n)
    {
        if(n==0)
        {
            int cnt0=0;
            for(int i=0;i<curr.size()-1;i++)
            {
                if(curr[i]=='0' && curr[i+1]=='0')cnt0++;
            }
            if(cnt0>0)return;
            ans.push_back(curr);
            return;
        }
        curr[n-1]='1';
        rec(curr,n-1);
        curr[n-1]='0';
        rec(curr,n-1);
    }
    vector<string> validStrings(int n) {
        string curr="";
        for(int i=0;i<n;i++)
        {
            curr+='0';
        }
        rec(curr,n);
        return ans;
    }
};