class Solution {
public:
    int ultarec(string text1, string text2)
    {
        int ultadp[1001][1001];
        for(int i=0;i<1001;i++)
        {
            ultadp[0][i]=0;
        }
        for(int i=0;i<1001;i++)
        {
            ultadp[i][0]=0;
        }

        for(int i=1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    ultadp[i][j]=1+ultadp[i-1][j-1];
                }
                else{
                    ultadp[i][j]=max(ultadp[i-1][j],ultadp[i][j-1]);
                }
            }
        }

        return ultadp[text1.size()][text2.size()];

    }
    int longestPalindromeSubseq(string s) {
     string t=s;
     reverse(t.begin(),t.end());   
     return ultarec(s,t);
    }
};