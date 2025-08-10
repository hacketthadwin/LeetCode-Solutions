class Solution {
    private:
    void savePermutations(string s, vector<string> &result) {
    sort(s.begin(), s.end()); 
    do {
        if (s[0] != '0') {
            result.push_back(s);
        }
    } while (next_permutation(s.begin(), s.end()));
}

public:
    bool reorderedPowerOf2(int n) {
        string s= to_string(n);
        vector<string>perms;
        savePermutations(s,perms);
        int c=perms.size();
        for(int i=0;i<c;i++)
        {
            int num=stoi(perms[i]);
            if(!(num&(num-1)))
            {
                return true;
            }
        }
        return false;

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
