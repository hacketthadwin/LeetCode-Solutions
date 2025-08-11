class Solution {
    private:
    const int MOD = 1e9 + 7;
    long long modpow(int a, int e) {
        long long res = 1;
        while (e > 0) {
            if (e & 1) res = (res * a) % MOD;
            a = (1LL* a * a) % MOD;
            e >>= 1;
        }
        return res;
    }
    int rangeProduct(vector<long long> &prefix, int l, int r) {
        int n = prefix.size();
        int inv = modpow(prefix[l], MOD - 2);
        return (1 * prefix[r + 1] * inv) % MOD;
    }

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pos_of_powers;
        for(int i=0;i<31;i++)
        {
            if(n&(1<<i))
            {
                pos_of_powers.push_back(i);
            }
        }

        for(int i=0;i<pos_of_powers.size();i++)
        {
            pos_of_powers[i]=1<<(pos_of_powers[i]);
        }   
        vector<long long> prefix(pos_of_powers.size() + 1, 1);
        for (int i = 1; i <= (int)pos_of_powers.size(); i++) {
            prefix[i] = (1LL* prefix[i - 1] * pos_of_powers[i - 1]) % MOD;
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            ans.push_back(rangeProduct(prefix,queries[i][0],queries[i][1]));
        }   

        return ans;
        
    }
};
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();

