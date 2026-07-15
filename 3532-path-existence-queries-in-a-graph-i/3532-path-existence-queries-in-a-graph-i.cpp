// Uncomment to enable debugging (LEETCODE SPECIAL DEBUG STATEMENTS)
#define DEBUG

#ifdef DEBUG
#define debug(x) do { \
    cout << #x << " = "; \
    _print(x); \
    cout << '\n'; \
} while (0)
#else
#define debug(x)
#endif

void _print(int x) { cout << x; }
void _print(long long x) { cout << x; }
void _print(unsigned x) { cout << x; }
void _print(unsigned long long x) { cout << x; }
void _print(char x) { cout << x; }
void _print(string x) { cout << x; }
void _print(bool x) { cout << (x ? "true" : "false"); }
void _print(double x) { cout << x; }

template<typename T1, typename T2>
void _print(pair<T1, T2> p) {
    cout << "{";
    _print(p.first);
    cout << ", ";
    _print(p.second);
    cout << "}";
}

template<typename T>
void _print(vector<T> v) {
    cout << "[ ";
    for (auto &x : v) {
        _print(x);
        cout << " ";
    }
    cout << "]";
}

template<typename T>
void _print(set<T> s) {
    cout << "{ ";
    for (auto &x : s) {
        _print(x);
        cout << " ";
    }
    cout << "}";
}

template<typename T>
void _print(multiset<T> s) {
    cout << "{ ";
    for (auto &x : s) {
        _print(x);
        cout << " ";
    }
    cout << "}";
}

template<typename T1, typename T2>
void _print(map<T1, T2> m) {
    cout << "{ ";
    for (auto &x : m) {
        _print(x);
        cout << " ";
    }
    cout << "}";
}
class unionfind{
    private:vector<int>p,rank;
    public:
    unionfind(int n)
    {
        rank.assign(n,0);p.assign(n,0);
        iota(p.begin(),p.end(),0);
    }
    int find_set(int i){return (p[i]==i) ? i : p[i]=find_set(p[i]);}
    bool is_same_set(int i,int j){return find_set(i)==find_set(j);}
    void union_set(int i,int j){
        if(!is_same_set(i,j))
        {
            int x=find_set(i),y=find_set(j);
            if(rank[x]>rank[y])p[y]=x;
            else
            {
                p[x]=y;
                if(rank[x]==rank[y])rank[y]++;
            }
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unionfind DSU(n);
        map<int,int>join_till_idx;
        for(int i=0;i<nums.size();i++)
        {
            int search=maxDiff+nums[i];
            auto it = lower_bound(nums.begin(),nums.end(),search);
            if((it!=nums.end()) && (*it==search))
            {
                join_till_idx[i]=(it-nums.begin());
            }
            else
            {
                join_till_idx[i]=(it-nums.begin()-1);
            }
        }

        for(auto m:join_till_idx)
        {
            int u=m.first;
            int v=m.second;
            DSU.union_set(u,v);
        }
        vector<bool>ans(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            int u=queries[i][0];
            int v=queries[i][1];
            if(DSU.is_same_set(u,v))
            {
                ans[i]=true;
            }
            else
            {
                ans[i]=false;
            }
        }

        return ans;
    }
};