class Solution {
public:   
    bool check(string t)
    {
        for(int i=0;i<t.size();i++)
        {
            if(t[i]!=t[t.size()-i-1])
            {
                return false;
            }
        }
        return true;
    }
    void rec(int level,string t,vector<vector<string>>&ans,vector<string>&temp)   
    {

        //you can add pruning case but its not necessary
        //base case
        if(level==t.size())     //removed level==t.size()-1 because by this condition i cannot check the last element of t string
        {
            ans.push_back(temp);
            return;
        }
         // Try all possible substrings starting from 'level'
        for (int i = level; i < t.size(); i++) {
            string substring = t.substr(level, i - level + 1);

            // If the substring is a palindrome, add it to temp and recurse
            if (check(substring)) {
                temp.push_back(substring);
                rec(i + 1, t, ans, temp);  // Recurse with the next level after the palindrome
                temp.pop_back();  // Backtrack by removing the last substring added to temp
            }
        }
        
        return;  
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        string p;
        rec(0,s,ans,temp);
        return ans;
        
    }
};