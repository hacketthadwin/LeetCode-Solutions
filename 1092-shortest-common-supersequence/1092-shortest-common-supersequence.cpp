class Solution {
public:
    string ultarec(string text1, string text2)
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

		int l=ultadp[text1.size()][text2.size()];
		string finans="";
        int i = text1.size();
        int j = text2.size();
        while (i > 0 && j > 0)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                finans += text1[i - 1];
                i--;
                j--;
            }
            else if (ultadp[i - 1][j] > ultadp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        reverse(finans.begin(),finans.end());
        string strans="";
         i = 0;
         j = 0;
        int k = 0;
		while (i < text1.size() && j < text2.size())
        {
            if (text1[i] == text2[j])
            {
                strans += text1[i];
                i++;
                j++;
                k++;
            }
            else
            {
                if(text1[i]==finans[k] && text2[j]!=finans[k]){
                    strans+=text2[j];
                    j++;
                }
                else if(text1[i]!=finans[k] && text2[j]==finans[k]){
                    strans+=text1[i];
                    i++;
                }
                else
                {
                    strans+=text2[j];
                    strans+=text1[i];
                    j++;
                    i++;
                }
            }
        }
        while(i <text1.size())
        {
            strans+=text1[i];
            i++;
        }
        while(j <text2.size())
        {
             strans+=text2[j];
             j++;
        }

        return strans;

    }

    string shortestCommonSupersequence(string str1, string str2) {
        return ultarec(str1,str2);
    }
};