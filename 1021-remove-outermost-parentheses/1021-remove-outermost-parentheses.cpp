class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        //this can be solved using stack
        vector<pair<int,int>>v;
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                if(st.size()==1)
                {
                    //i will push the substring from i+1 to current index - 1
                    v.push_back({st.top()+1,i-1});
                }
                st.pop();
            }
        }

        for(int i=0;i<v.size();i++)
        {
            ans+=s.substr(v[i].first,v[i].second-v[i].first+1);
        }
        return ans;
    }
};