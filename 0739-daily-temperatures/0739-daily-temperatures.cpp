class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
       stack<int>st;
       vector<int>ans(t.size(),0);
       for(int i=t.size()-1;i>=0;i--)
       {  
            while(!st.empty() && t[i]>=t[st.top()])
            {
                st.pop();
            } 
            if(!st.empty())
            {
                ans[i]=st.top()-i;
            }
            st.push(i);
            
       }
       return ans;
    }
};

//  deque<int>dq;
//         vector<int>ans;
//         for(int i=t.size()-1;i>=0;i--)
//         {
            
//             if(dq.empty())
//             {
//                 ans.push_back(0);
//                 dq.push_back(i);
//             }
//             else
//             {
//                 if(t[i]<=t[dq.back()])
//                 {
//                     ans.push_back(dq.back()-i);
//                     dq.push_back(i);
//                 }
//                 else
//                 {
                    
//                     while(!dq.empty() && t[dq.back()]<t[i])
//                     {
//                         dq.pop_back();
//                     }
//                     dq.push_back(i);
//                     ans.push_back(i-dq.back());
//                 }
               
//             }
//         }

//         return ans;