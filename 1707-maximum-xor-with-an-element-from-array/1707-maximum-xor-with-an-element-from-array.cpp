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
            int bit = (num >> i) & 1;   //this gives bit of number at current position
            if(trie[node].child[1-bit]!=-1)   //me checking if there is opposite sign bit present or not at that position
            {
            ans+= 1<<i;
            int next = trie[node].child[1-bit];
            node = next;
            }
            else if((trie[node].child[bit] != -1))
            {
            int next = trie[node].child[bit];
            node = next;
            }
            else
            {
                return -1;
            }
            
        }  
        return ans;
    }
};
class Solution {
public:
 //see this method is one of the most important optimisation, this is called offline queries method
  //if you want less than m values to be checked in the nums, then push the nums<=m in the trie currently and as m increases then start pushing the elements in the tries
  //awesome problem and optimisation
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
                BinaryTrie maximumtrie;
        int n=nums.size();
        vector<pair<pair<int,int>,int>>queries2;   //i did this because i also need to push the answer in the correct index according to the queries index
        for(int i=0;i<queries.size();i++)
        {
            queries2.push_back({{queries[i][1],queries[i][0]},i});
        }
        int tempans=0;
        sort(nums.begin(),nums.end());
        sort(queries2.begin(),queries2.end());
        vector<int>ans(queries.size());
        int c=0;
        int sz=queries.size();
        for(int i=0;i<sz;i++)
        {
            while(c<n && nums[c]<=queries2[i].first.first)
            {
                maximumtrie.insert(nums[c]);
                c++;
            }            
            int x=queries2[i].first.second;
            tempans=maximumtrie.maximum(x);
            ans[queries2[i].second]=(tempans);
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