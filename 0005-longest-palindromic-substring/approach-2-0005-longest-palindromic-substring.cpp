class Solution {
public:
//this code is awesome representation of using center expansion to check maximum palindrome in the string
//what we do is first we take one index at a time, if we have been given odd size string then, (i,i) as the center
//or if we have been given even size string, then i,i+1 as the center where i is starting index and (i+1) is the ending index
//then we keep expanding the start and end from both side till the forming string is a palindrome
//this we way we check palindrome for all index and it is also n^2 time complexity
auto check(int s,int e,string st)
{
    while(s>=0 && e<=st.size()-1 && st[s]==st[e])
    {
        s--;
        e++;
    }
    return st.substr(s+1,(e-1)-(s+1)+1); 
}
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        string t="";
        for(int i=0;i<s.size()-1;i++)
        {
            string odd=check(i,i,s);
            string even=check(i,i+1,s);
            if(odd.size()>t.size())t=odd;
            if(even.size()>t.size())t=even;
        }
        return t;
    }
};
