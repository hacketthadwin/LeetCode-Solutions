class Solution {
public:
    string simplifyPath(string s) {
        //ok so there are certain rules, multiple slashes will be considered as one 
        //single dots will be ignored, double dots will mean that we need to visit previous value, so in the stack we will remove the top most element, more than 2 dots means it is directory name and need to be added to the stack as a directory file
        //path must start with / and must not end with /
        //directory will be seperated by / only, 
        //there must not be 1 or 2 dots
        int n=s.size();
        stack<string>st;

        for(int i=0;i<n;)
        {
            if(s[i]=='/')
            {
                while(i<n && s[i]=='/') i++;
            }

                if (s[i] == '.') 
                {
                int cnt = 0;
                while (i < n && s[i] == '.') 
                {
                    cnt++;
                    i++;
                }

                if ((i == n || s[i] == '/') && cnt == 1) continue;
                if ((i == n || s[i] == '/') && cnt == 2) 
                {
                    if (!st.empty()) st.pop();
                    continue;
                }

                string temp = "";
                while (cnt--) temp += '.';
                while (i < n && s[i] != '/') 
                {
                    temp += s[i];
                    i++;
                }
                st.push(temp);
                continue;
            }


            if(i < n && ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')))
            {
                string temp="";
                while(i<n && s[i]!='/')
                {
                    temp+=s[i];
                    i++;
                }
                st.push(temp);
            }
        }

        // Repeat the same processing once more
        vector<string> vals;
        while (!st.empty()) {
            vals.push_back(st.top());
            st.pop();
        }
        reverse(vals.begin(), vals.end());

        string ans = "/";
        for (int i = 0; i < vals.size(); i++) {
            ans += vals[i];
            if (i != vals.size() - 1) ans += "/";
        }

        return ans;

    }
};