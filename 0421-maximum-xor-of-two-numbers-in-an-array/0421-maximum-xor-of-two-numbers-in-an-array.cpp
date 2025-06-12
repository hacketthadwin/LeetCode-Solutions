const int MAX_BITS = 63; // For 64-bit unsigned integers

struct BinaryTrieNode {
    int child[2];
    int num_going_below;
    int num_ending_here;

    BinaryTrieNode() {
        child[0] = child[1] = -1;
        num_going_below = 0;
        num_ending_here = 0;
    }
};

struct BinaryTrie {
    vector<BinaryTrieNode> trie;

    BinaryTrie() {
        trie.push_back(BinaryTrieNode());
    }

    void insert(uint64_t num) {
        int node = 0;
        for (int i = MAX_BITS; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (trie[node].child[bit] == -1) {
                trie[node].child[bit] = trie.size();  //trie.size() gives the index where the next new node will be placed in the trie vector.
                trie.push_back(BinaryTrieNode());   //This actually adds the new node to the trie vector.
            }
            node = trie[node].child[bit];
            trie[node].num_going_below++;
        }
        trie[node].num_ending_here++;
    }

    bool search(uint64_t num) {
        int node = 0;
        for (int i = MAX_BITS; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (trie[node].child[bit] == -1)
                return false;
            node = trie[node].child[bit];
        }
        return trie[node].num_ending_here > 0;
    }

    void erase(uint64_t num) {
        if (!search(num)) return;
        int node = 0;
        for (int i = MAX_BITS; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int next = trie[node].child[bit];
            trie[next].num_going_below--;
            if (trie[next].num_going_below == 0)trie[node].child[bit] = -1;
            node = next;
        }
        trie[node].num_ending_here--;
    }
    int maximum(uint64_t num)
    {
        int ans=0;
        int node = 0;
        for (int i = MAX_BITS; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(trie[node].child[1-bit]!=-1)
            {
            ans+= 1<<i;
            int next = trie[node].child[1-bit];
            if (trie[next].num_going_below == 0)return ans;
            node = next;
            }
            else
            {
            int next = trie[node].child[bit];
            if (trie[next].num_going_below == 0)return ans;
            node = next;
            }
        }  
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        BinaryTrie maximumtrie;
        int n=nums.size();
        int tempans=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maximumtrie.insert(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            tempans=maximumtrie.maximum(nums[i]);
            ans=max(ans,tempans);
        }
        return ans;

    }
};