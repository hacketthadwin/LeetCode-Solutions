class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>pos(26,-1);
        for(int i=0;i<s.size();i++)
        {
            pos[s[i]-'a']=i;
        }
        int max_till_now=-1;
        int st=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            max_till_now=max(max_till_now,pos[s[i]-'a']);
            if(i==max_till_now)
            {
                ans.push_back(i-st+1);
                max_till_now=-1;
                st=i+1;
            }
        }
        return ans;
    }
};