class StockSpanner {
public:
stack<int>st;
vector<int>el;
map<int,int>mp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int temp=1;
        while(!st.empty() && price>=st.top())
        {
            temp+=mp[st.top()];
            st.pop();
        }
        st.push(price);
        int ans=temp;
        el.push_back(price);
        mp[price]=ans;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */