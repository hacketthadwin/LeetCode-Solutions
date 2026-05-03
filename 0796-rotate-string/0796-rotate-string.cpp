class Solution {
public:
    bool rotateString(string s, string goal) {
        //obviously you know the brute force, but let's learn the optimal approach for the problem
        //so for the optimal approach what we going to do is we will create a new string t= s+s
        //and we start iterating and if at any point we find that any part of t and goal string is same, then yes, we found our rotated string
        if(s.size()!=goal.size())return false;
        string t = s;
        t+=s;
        int n=s.size();
        //KMP would be most efficient here, but i can't remember it rn :) 
        for(int j=0;j<n;j++)
        {
            int i=0;
            while(i<n && t[j+i]==goal[i])i++;
            if(i==n)return true;
        }
        return false;

    }
};