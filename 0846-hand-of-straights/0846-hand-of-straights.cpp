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
template<typename T, typename Container, typename Compare>
void _print(priority_queue<T, Container, Compare> pq) {
    cout << "[ ";
    while (!pq.empty()) {
        _print(pq.top());
        cout << " ";
        pq.pop();
    }
    cout << "]";
}
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

class Solution {
public:

    bool isNStraightHand(vector<int>& hand, int gsz) {
        if((hand.size()%gsz)!=0)return false;
        int cnt_groups=(hand.size()/gsz);
        sort(hand.begin(),hand.end());
        map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        for(int i=0;i<hand.size();i++)
        {
            int el=hand[i];
            if(mp.count(el-1))
            {
                int sz=mp[el-1].top();
                if(sz<gsz)
                {
                    mp[el-1].pop();
                    if(mp[el-1].size()==0)mp.erase(el-1);
                    mp[el].push(sz+1); //considering i took el and joined it to the last number
                }
                else
                {
                    mp[el].push(1);
                }
            }
            else
            {
                mp[el].push(1);
            }
        }
        // debug(mp);
        // return 1;

        for(auto m:mp)
        {
            while(!m.second.empty())
            {
                if(m.second.top()!=gsz)
                {
                    return false;
                }
                m.second.pop();
            }
        }

        return true;
        

    }
};