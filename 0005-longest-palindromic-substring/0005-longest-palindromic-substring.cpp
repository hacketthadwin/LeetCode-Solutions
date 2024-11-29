class Solution {
public:
      string t = ""; 
//reduced time complexity check of palindrome 
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
//this code is an example of iterative dp where we used continue function to skip the unnecessary states
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (j - i + 1 <= t.size()) continue;
                if (isPalindrome(s, i, j)) {
                    t = s.substr(i, j - i + 1); 
                }
            }
        }
        return t;
    }
};
