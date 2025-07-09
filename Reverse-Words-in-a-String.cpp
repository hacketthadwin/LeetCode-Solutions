class Solution {
public:

//average 2 pointers problem
    string reverseWords(string s) {
        int i=0;
        int j=0;
        vector<string>words;
        for(;j<s.size();j++)
        {
            if(  s[j]==' ')
            {
                if(j>i)   //you cannot add this condition in parent if condition using && because we have to set i==j+1 in any condition if s[j]==' ', and also this j>i removes all the continous spaces from the string
                //this is very important condition
                {
                string t= s.substr(i,(j-1)-i+1);
                words.push_back(t);
                }
                i=j+1;
            }
        }


        if(j>i)
        {
            string t = s.substr(i, j - i);
            words.push_back(t);
        }

        reverse(words.begin(),words.end());
        string ans;
        for (int k = 0; k < words.size(); k++) {
            ans += words[k];
            if (k != words.size() - 1)
                ans += " ";
        }

        return ans;
        
    }
};