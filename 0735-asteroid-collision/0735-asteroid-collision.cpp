class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        // deque<int>dq;
        // for(int i=0;i<arr.size();i++)
        // {
        //     while(!dq.empty() && arr[i]>arr[dq.back()] && ((arr[i]<0 && arr[dq.back()]>0)||(arr[i]>0 && arr[dq.back()]<0)))
        //     {
        //         dq.pop_back();
        //     }
        //     if((dq.empty()) || ((arr[i]<0 && arr[dq.back()]<0)||(arr[i]>0 && arr[dq.back()]>0)))
        //     {
        //         dq.push_back(i);
        //     }
        // }

        // vector<int>ans;
        // while(!dq.empty())
        // {
        //     ans.push_back(arr[dq.back()]);
        //     dq.pop_back();
        // }

        // return ans;

        stack<int>st;
        for(int i=0;i<arr.size();i++)
        {
            bool is_equal=false;
            if(!st.empty() && ((arr[i]<=0 && arr[st.top()]>=0)))
            {
                if(abs(arr[i])<abs(arr[st.top()]))continue;
                // if(abs(arr[i])==abs(arr[st.top()]))
                // {
                //     st.pop();
                //     continue;
                // }
                while(!st.empty() && ((arr[i]<0 && arr[st.top()]>0)) && (abs(arr[i])>=abs(arr[st.top()])))
                {
                    if((abs(arr[i])==abs(arr[st.top()])))
                    {
                        is_equal=true;
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if(!st.empty() && abs(arr[i])<abs(arr[st.top()]) && ((arr[i]<=0 && arr[st.top()]>=0)))continue;
                if(is_equal)continue;
            }

            st.push(i);
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(arr[st.top()]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};