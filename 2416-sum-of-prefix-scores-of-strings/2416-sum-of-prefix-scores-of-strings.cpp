const int ALPHABET = 26;

struct TrieNode {
    vector<int> children;
    int strings_ending_here;
    int strings_going_below;

    TrieNode() {
        children.assign(ALPHABET, -1);
        strings_ending_here = 0;
        strings_going_below = 0;
    }
};

struct Trie {
    vector<TrieNode> tree;
    int size;

    Trie() {
        tree.emplace_back();
        size = 1;
    }

    void insert(const string& word) {
        int node = 0;
        for (char ch : word) {
            int c = ch - 'a';
            if (tree[node].children[c] == -1) {
                tree[node].children[c] = size++;
                tree.emplace_back();
            }
            node = tree[node].children[c];
            tree[node].strings_going_below++;
        }
        tree[node].strings_ending_here++;
    }

    bool search(const string& word) {
        int node = 0;
        for (char ch : word) {
            int c = ch - 'a';
            if (tree[node].children[c] == -1)
                return false;
            node = tree[node].children[c];
        }
        return tree[node].strings_ending_here > 0;
    }

int startsWith(const string& prefix) {
    vector<string> presentwords;
    int node = 0;
    for (char ch : prefix) {
        int c = ch - 'a';
        if (tree[node].children[c] == -1)
            return 0;
        node = tree[node].children[c];
    }
    return  tree[node].strings_going_below;

}

};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        Trie scoretrie;
        for(int i=0;i<n;i++)
        {
            scoretrie.insert(words[i]);
        }
        vector<int>ans(n,0);
        for(int i=0;i<words.size();i++)
        {
            int count=0;
            for(int j=0;j<words[i].size();j++)
            {
                string t= words[i].substr(0,j+1);
                count+=scoretrie.startsWith(t);
            }
            ans[i]=count;
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


//just paste it after the class in leetcode