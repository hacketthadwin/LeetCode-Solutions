class Solution {
public:
    int numberOfSubstrings(string s) {
        //this can get solved using map
        // map<char,int>mp;
        // int l=0,r=0,ans=0;
        // while(r<s.size())
        // {
        //     mp[s[r]]++;
        //     while((l<=r) && mp['a']>=1 && mp['b']>=1 && mp['c']>=1)
        //     {
        //         ans+=(s.size()-r);
        //         mp[s[l]]--;
        //         l++;
        //     }
            
        //     r++;
        // }
        // return ans;

        //the above was my method of solving but this problem can be solved in much better approach and time + space complexity
        //the below is most optimal approach of solving using striver's method
        vector<int>cnt={-1,-1,-1};
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            cnt[s[i]-'a']=i;
            if((cnt[0]!=-1) && (cnt[1]!=-1) && (cnt[2]!=-1))
            {
                ans= ans+(1+min({cnt[0],cnt[1],cnt[2]}));
            }
        }
        return ans;
    }
};