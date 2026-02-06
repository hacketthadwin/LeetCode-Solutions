class Solution {
public:
// this is trie problem
    string longestCommonPrefix(vector<string>& strs) {
        string curr_string = strs[0];
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].size()<curr_string.size())
            {
                int j=0;
                string temp="";
                while((j<strs[i].size()) && (strs[i][j]==curr_string[j]))
                {
                    temp+=strs[i][j];
                    j++;
                }
                curr_string=temp;
            }
            for(int j=0;j<curr_string.size();j++)
            {
                if(curr_string[j]!=strs[i][j])
                {
                    curr_string = curr_string.substr(0,j);
                    break;
                }
            }
        }
        return curr_string;
    }
};