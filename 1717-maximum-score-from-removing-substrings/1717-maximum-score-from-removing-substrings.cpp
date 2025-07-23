class Solution {
public:

int processString(string& s, char first, char second, int value) {
    stack<char> st;
    int gain = 0;
    for (char c : s) {
        if (!st.empty() && st.top() == first && c == second) {
            st.pop();
            gain += value;
        } else {
            st.push(c);
        }
    }
    string rem;
    while (!st.empty()) {
        rem += st.top();
        st.pop();
    }
    reverse(rem.begin(), rem.end());
    s = rem;
    return gain;
}

    int maximumGain(string s, int x, int y) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

    vector<string> blocks;
    string temp;

    for (char c : s) {
        if (c == 'a' || c == 'b') {
            temp += c;
        } else {
            if (!temp.empty()) {
                blocks.push_back(temp);
                temp.clear();
            }
        }
    }
    if (!temp.empty()) blocks.push_back(temp);
    char first = 'a', second = 'b';
    int high = x, low = y;
    if (y > x) {
        swap(first, second);
        swap(high, low);
    }

    int total = 0;
    for (string& block : blocks) {
        total += processString(block, first, second, high);
        total += processString(block, second, first, low);
    }

    return total;
    }
};

        // stack<int>st;
        // int n=s.size();
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(s[i]=='a' || s[i]=='b')
        //     {
        //         if(st.empty())
        //         {
        //             st.push(i);
        //         }
        //         else
        //         {
        //             if(s[st.top()]==s[i])
        //             {
        //                 st.push(i);
        //             }
        //             else
        //             {
        //                 string t=string(1, s[st.top()]) + s[i];
        //                 st.pop();
        //                 if(t=="ab")
        //                 {
        //                     ans+=x;
        //                 }
        //                 else  //this means ba
        //                 {
        //                     ans+=y;
        //                 }
        //             }
        //         }
        //     }
        //     else
        //     {
        //                 while (!st.empty()) {
        //                 st.pop();
        //             }

        //     }
        // }
        // return ans;

        //see let's start with greedy approach
        //first take values with higher values either x or y, then after taking it