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
    int node = 0;
    for (char ch : prefix) {
        int c = ch - 'a';
        if (tree[node].children[c] == -1)
            return 0;
        node = tree[node].children[c];
    }
    return tree[node].strings_going_below;
}
};
class Solution {
public:
    string longestWord(vector<string>& words) {
         int n = words.size();
        vector<pair<int, string>> count;

        Trie longesttrie;
        for (int i = 0; i < n; i++) {
            longesttrie.insert(words[i]);
        }

        for (int i = 0; i < n; i++) {
            int prefixCount = 0;
            string prefix = "";
            for (char ch : words[i]) {
                prefix += ch;
                if (longesttrie.search(prefix))
                    prefixCount++;
                else
                    break;
            }
            // only valid if all prefixes are present
            if (prefixCount == words[i].size()) {
                count.push_back({prefixCount, words[i]});
            }
        }

        if (count.empty()) return "";
        sort(count.begin(), count.end(), [](auto& a, auto& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        return count[0].second;
    }
};