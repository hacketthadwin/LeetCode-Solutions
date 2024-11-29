class Solution {
public:
     vector<int>p;  // Stores the radius of the palindrome centered at each position

    // Function to run Manacher's algorithm on the modified string
    vector<int> run_manacher(const string& s) {
        int n = s.size();
        p.assign(n, 0);
        int center = 0, right = 0; // center and right boundary of the current palindrome

        for (int i = 1; i < n - 1; i++) {
            // Find the mirror index
            int mirror = 2 * center - i;

            // If within the right boundary, use the mirrored value
            if (i < right)
                p[i] = min(right - i, p[mirror]);

            // Attempt to expand the palindrome centered at `i`
            while (s[i + 1 + p[i]] == s[i - 1 - p[i]])
                p[i]++;

            // Update the center and right boundary if the expanded palindrome goes beyond the current right boundary
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }
        return p;
    }

    // Function to preprocess the string (insert `#` between characters)
    string preprocess(const string& s) {
        string t = "^#"; // Add '^' at the beginning and '$' at the end to avoid boundary checking
        for (char c : s) {
            t += c;
            t += "#";
        }
        t += "$";
        return t;
    }

    // Function to find the longest palindromic substring
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        string t = preprocess(s); // Preprocess the string
        p = run_manacher(t); // Run Manacher's algorithm
        
        // Find the maximum length palindrome
        int maxLen = 0, centerIndex = 0;
        for (int i = 1; i < p.size() - 1; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }

        // Extract the substring from the original string
        int start = (centerIndex - 1 - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};