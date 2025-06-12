#include <bits/stdc++.h>
using namespace std;

const int ALPHABET = 26;

struct TrieNode {
    vector<int> children;
    int strings_ending_here;
    int strings_going_below;

    TrieNode() {
        children.assign(ALPHABET, -1);  // -1 means no child
        strings_ending_here = 0;
        strings_going_below = 0;
    }
};

struct Trie {
    vector<TrieNode> tree;
    int size;

    Trie() {
        tree.emplace_back();  // root node
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

    bool startsWith(const string& prefix) {
        int node = 0;
        for (char ch : prefix) {
            int c = ch - 'a';
            if (tree[node].children[c] == -1)
                return false;
            node = tree[node].children[c];
        }
        return true;
    }

    int countPrefix(const string& prefix) {
        int node = 0;
        for (char ch : prefix) {
            int c = ch - 'a';
            if (tree[node].children[c] == -1)
                return 0;
            node = tree[node].children[c];
        }
        return tree[node].strings_going_below + tree[node].strings_ending_here;
    }

    void deleteWord(const string& word) {
        if (!search(word)) return;

        int node = 0;
        for (char ch : word) {
            int c = ch - 'a';
            int child = tree[node].children[c];

            tree[child].strings_going_below--;
            if (tree[child].strings_going_below == 0 && tree[child].strings_ending_here == 0) {
                tree[node].children[c] = -1;
            }

            node = child;
        }
        tree[node].strings_ending_here--;
    }
};
