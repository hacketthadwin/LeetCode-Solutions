class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k>0)
        {
            deque<int>dq;
            map<int,int>mp;
            int cnt=k;
            for(int i=0;i<num.size();i++)
            {
                while(!dq.empty() && (num[dq.back()]-'0')>(num[i]-'0') && k>0)
                {
                    mp[dq.back()]=1;
                    dq.pop_back();
                    k--;
                }
                dq.push_back(i);
            }
            // while(!dq.empty() && k--)
            // {
            //     mp[dq.front()]=1;
            //     dq.pop_front();
            // }
            //now let's first construct the string
            string temp="";
            for(int i=0;i<num.size();i++)
            {
                if(!mp.count(i))
                {
                    temp+=num[i];
                }
            }

            if(cnt==k)
            {
                //remove last k digit from num;
                temp=num.substr(0,num.size()-k);
                k=0;
            }
            num=temp;
            if(k<=0)break;
        }
        size_t pos = num.find_first_not_of('0');
        num = (pos == std::string::npos) ? "0" : num.substr(pos);
        return num;
    }
};