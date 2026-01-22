class Solution {
public:
    int maxScore(string s) {
        vector<int>cnt(s.size(),0);
        if(s[0]=='1')
        {
            cnt[0]++;
        }
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                cnt[i]++;
            }
            cnt[i]+=cnt[i-1];
        }
        int ans=0;
        for(int i=0;i<s.size()-1;i++)
        {
            //at i=2, cnt[2] = 1 , a= 2-1+1=2, b=3 
            int a=i-cnt[i]+1;
            int b=cnt[s.size()-1]-cnt[i];
            ans=max(ans,a+b);
        }
        return ans;

    }
};