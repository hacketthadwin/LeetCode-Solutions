class Solution {
public:
//the below trie structure was for the bfs idea
// static const int letters = 26;

// struct TrieNode {
//     vector<int> children;
//     vector<int> strings_ending_here;
//     int strings_going_below;


//     TrieNode() {
//         children.resize(letters, -1);
//         strings_going_below = 0;
//     }
// };

// struct Trie {
//     vector<TrieNode> TrieTree;
//     int sizeOfTrie = 0;

//     Trie() {
//         TrieTree.push_back(TrieNode());
//         sizeOfTrie++;
//     }

//     void add(string word,int idx) {
//         int currNode = 0;
//         for (char ch : word) {
//             int index = ch - 'a';
//             if (TrieTree[currNode].children[index] == -1) {
//                 TrieTree[currNode].children[index] = sizeOfTrie;
//                 TrieTree.push_back(TrieNode());
//                 sizeOfTrie++;
//             }
//             currNode = TrieTree[currNode].children[index];
//             TrieTree[currNode].strings_going_below++;
//         }
//         TrieTree[currNode].strings_ending_here.push_back(idx);
//     }

//     bool search(string word) {
//         int currNode = 0;
//         for (char ch : word) {
//             int index = ch - 'a';
//             if (TrieTree[currNode].children[index] == -1)
//                 return false;
//             currNode = TrieTree[currNode].children[index];
//         }
//         return TrieTree[currNode].strings_ending_here.size() > 0;
//     }

//     void delete_string(string word,int idx) {
//         if (search(word) == false) return;

//         int currNode = 0;
//         for (char ch : word) {
//             int index = ch - 'a';
//             int child = TrieTree[currNode].children[index];
//             TrieTree[child].strings_going_below--;

//             if (TrieTree[child].strings_going_below == 0)
//                 TrieTree[currNode].children[index] = -1;

//             currNode = child;
//         }
//         TrieTree[currNode].strings_ending_here.erase(remove(TrieTree[currNode].strings_ending_here.begin(), TrieTree[currNode].strings_ending_here.end(), idx), TrieTree[currNode].strings_ending_here.end());;
//     }
// };

//this is for the preprocessing idea
static const int letters = 26;

struct TrieNode {
    vector<int> children;
    int strings_ending_here;
    int strings_going_below;
    int best_idx;

    TrieNode() {
        children.resize(letters, -1);
        strings_ending_here = 0;
        strings_going_below = 0;
        best_idx=-1;
    }
};

struct Trie {
    vector<TrieNode> TrieTree;
    int sizeOfTrie = 0;

    Trie() {
        TrieTree.push_back(TrieNode());

        sizeOfTrie++;
    }

    void add(string word,int idx,vector<string>& wordsContainer) {
        int currNode = 0;
        for (char ch : word) {
            int index = ch - 'a';
            if (TrieTree[currNode].children[index] == -1) {
                TrieTree[currNode].children[index] = sizeOfTrie;
                TrieTree.push_back(TrieNode());
                sizeOfTrie++;
            }
            currNode = TrieTree[currNode].children[index];
            TrieTree[currNode].strings_going_below++;
                if(TrieTree[currNode].best_idx==-1 || word.size()<wordsContainer[TrieTree[currNode].best_idx].size())
                {
                    TrieTree[currNode].best_idx=idx;
                }
        }
        TrieTree[currNode].strings_ending_here++;
    }

    bool search(string word) {
        int currNode = 0;
        for (char ch : word) {
            int index = ch - 'a';
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
            int index = ch - 'a';
            int child = TrieTree[currNode].children[index];
            TrieTree[child].strings_going_below--;

            if (TrieTree[child].strings_going_below == 0)
                TrieTree[currNode].children[index] = -1;

            currNode = child;
        }
        TrieTree[currNode].strings_ending_here--;
    }
};
int global_min_idx=-1;
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
//yeah the best solution is either tries or hashing
//may be hashing can be a better choice beause we can then apply the binary search to find the longest common suffix in it, also it is talking about suffix, we can make it prefix by reversing every string in it
//nah but tries because it is usually better choice for vector of strings

//first thought was bfs on trie
//like keep moving till the suffix matches, and whenever mismatch happens,
//start bfs from that node because the nearest ending string would give the minimum length string
//and if multiple strings end on same bfs level, choose minimum index among them

//but bfs can repeatedly traverse huge subtrees for every query
//so better idea is preprocessing the trie itself

//for every node store the best_idx
//meaning among all strings passing through this node,
//which string is best according to:
//1. minimum length
//2. if same length then minimum index

//now while querying, just move as deep as possible
//deepest reachable node itself represents the longest common suffix
//and node.best_idx directly gives the answer

//even root node stores the globally best answer,
//which automatically handles the empty suffix case
        int n = (int)wordsContainer.size();
        Trie t;
        int sz=INT_MAX;

        for(int i=0;i<n;i++)
        {
            reverse(wordsContainer[i].begin(),wordsContainer[i].end());
            t.add(wordsContainer[i],i,wordsContainer);
            if(wordsContainer[i].size()<sz)
            {
                sz=(int)wordsContainer[i].size();
                global_min_idx=i;
            }
        }

        


        
        vector<int>ans;
        for(int i=0;i<wordsQuery.size();i++)
        {
            int st=0;
            string s= wordsQuery[i];
            reverse(s.begin(),s.end());
            int tempans = -1;
            for(int j=0;j<s.size();j++)
            {
                if(t.TrieTree[st].children[s[j]-'a']!=-1)
                {
                    st = t.TrieTree[st].children[s[j]-'a'];
                    tempans=t.TrieTree[st].best_idx;
                }
                else
                {
                    break;
                }
            }
                    if(tempans==-1)
                    {
                        tempans=global_min_idx;
                    }
            ans.push_back(tempans);
        }
        return ans;
        


        
    }
};