class Solution {
public:
static const int letters = 10;

struct TrieNode {
    vector<int> children;
    int strings_ending_here;
    int strings_going_below;

    TrieNode() {
        children.resize(letters, -1);
        strings_ending_here = 0;
        strings_going_below = 0;
    }
};

struct Trie {
    vector<TrieNode> TrieTree;
    int sizeOfTrie = 0;

    Trie() {
        TrieTree.push_back(TrieNode());
        sizeOfTrie++;
    }

    void add(string word) {
        int currNode = 0;
        for (char ch : word) {
            int index = ch - '0';
            if (TrieTree[currNode].children[index] == -1) {
                TrieTree[currNode].children[index] = sizeOfTrie;
                TrieTree.push_back(TrieNode());
                sizeOfTrie++;
            }
            currNode = TrieTree[currNode].children[index];
            TrieTree[currNode].strings_going_below++;
        }
        TrieTree[currNode].strings_ending_here++;
    }

    bool search(string word) {
        int currNode = 0;
        for (char ch : word) {
            int index = ch - '0';
            if (TrieTree[currNode].children[index] == -1)
                return false;
            currNode = TrieTree[currNode].children[index];
        }
        return TrieTree[currNode].strings_ending_here > 0;
    }

    void delete_string(string word) {
        if (search(word) == false) return;

        int currNode = 0;
        for (char ch : word) {
            int index = ch - '0';
            int child = TrieTree[currNode].children[index];
            TrieTree[child].strings_going_below--;

            if (TrieTree[child].strings_going_below == 0)
                TrieTree[currNode].children[index] = -1;

            currNode = child;
        }
        TrieTree[currNode].strings_ending_here--;
    }
};
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        //so this can be solved using trie by moving down simultaneously in both the graphs and the longest we can go is the maximum length of the common prefix using dfs, eassy boyy
        //the above was basically first method of solving
        //the second method can be to only create trie of one array of string and then iterate through the other array of string for each string in that, match the characters as long as it is going and stop when it gets different
        Trie t1,t2;
        for(int i=0;i<arr1.size();i++)
        {
            string s=to_string(arr1[i]);
            t1.add(s);
        }
        for(int i=0;i<arr2.size();i++)
        {
            string s=to_string(arr2[i]);
            t2.add(s);
        }
        int ans=0;
        for(int i=0;i<arr2.size();i++)
        {
            int curr=0;
            
            string temp=to_string(arr2[i]);
            int tempans=0;
            for(int j=0;j<temp.size();j++)
            {
                if(t1.TrieTree[curr].children[temp[j]-'0']!=-1)
                {
                    tempans++;
                    curr=t1.TrieTree[curr].children[temp[j]-'0'];
                }
                else
                {
                    break;
                }
            }
            ans=max(ans,tempans);
        }

        return ans;
    }
};