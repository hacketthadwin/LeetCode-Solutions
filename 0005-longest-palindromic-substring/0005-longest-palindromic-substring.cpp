class Solution {
public:
      string t = ""; 
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