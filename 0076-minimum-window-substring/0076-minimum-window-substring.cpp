class Solution {
public:
    string minWindow(string s, string t) {
        //i can make 2 maps, one which will save all the chars i want to have, and one will save for the window and then from that i can check that for current window if it is possible to make the string shorter or not
        map<char,int>mp1,mp2; //mp1 is for t and mp2 is for s string
        for(int i=0;i<t.size();i++)
        {
            mp1[t[i]]++;
        }
        int i=0,j=0,ans_i=-1,ans_j=(int)s.size()+5;
        int cnt=0;
        while(j<s.size())
        {
            mp2[s[j]]++;

            if(mp1.count(s[j]) && mp2[s[j]] == mp1[s[j]])
            {
                cnt++;
            }

            while((i<=j) && cnt == mp1.size())
            {
                if((j-i+1)<((int)ans_j-ans_i+1))
                {
                    ans_i=i;
                    ans_j=j;
                }
                if(mp1.count(s[i]) && mp2[s[i]] == mp1[s[i]])
                {
                    cnt--;
                }
                mp2[s[i]]--;
                i++;
            }
            j++;
        }

        if(ans_i==-1 || ans_j==s.size()+5)
        {
            return "";
        }
        return s.substr(ans_i,ans_j-ans_i+1);
    }
};