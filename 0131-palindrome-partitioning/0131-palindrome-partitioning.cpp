class Solution {
public:
//we will solve this problem using matrix chain multiplication approach
    vector<vector<string>>finans;
    bool ispalindrome(string t)
    {
        for(int i=0;i<t.size();i++)
        {
            if(t[i]!=t[t.size()-i-1])return false;
        }
        return true;
    }
    void rec(string s,int i,int j,vector<string>tempans)
    {
        if(i>j)
        {
            finans.push_back(tempans);
            return;
        }
        for(int k=i;k<=j;k++)   //by just one change that is k<j to k<=j i got from empty answer to correct answer, so remember this debug thing...okay?
        {
            string t= s.substr(i, k - i + 1);
            if(ispalindrome(t))
            {
                tempans.push_back(t);
                rec(s, k + 1, j, tempans);
                tempans.pop_back();
            }
        }

    }
    
    vector<vector<string>> partition(string s) {
        vector<string>tempans;
        rec(s,0,s.size()-1,tempans);
        return finans;
    }
};