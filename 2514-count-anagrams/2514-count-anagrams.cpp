class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long facto(int n) {
        long long result = 1;
        for (int i = 2; i <= n; i++) {
            result = (result * i) % MOD;
        }
        return result;
    }

    long long modInverse(long long x, int mod) {
        long long res = 1, power = mod - 2;
        while (power > 0) {
            if (power % 2 == 1) res = (res * x) % mod;
            x = (x * x) % mod;
            power /= 2;
        }
        return res;
    }

    long long count(string& s) {
        int sz = s.size();
        vector<int> cnt(26, 0);
        long long fac = 1;

        for (int i = 0; i < sz; i++) {
            cnt[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) { 
            fac = (fac * facto(cnt[i])) % MOD;
        }
        return (facto(sz) * modInverse(fac, MOD)) % MOD;
    }

    int countAnagrams(string s) {
       vector<string> v;
        int i = 0;

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ' ') {
                v.push_back(s.substr(i, j - i));
                i = j + 1;
            }
        }
        if (i < s.size()) {
            v.push_back(s.substr(i)); //adding last word
        }

        long long ans = 1;
        for (int i = 0; i < v.size(); i++) {
            ans = (ans * count(v[i])) % MOD;
        }
        return ans;
    }
};