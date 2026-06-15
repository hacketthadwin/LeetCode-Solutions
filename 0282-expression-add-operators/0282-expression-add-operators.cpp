class Solution {
public:
vector<string>ans;
vector<char>operations={'+','-','*'};
long long value_finder(const string& temp)
{
    long long nums[20];
    char ops[20];
    int num_idx=0;
    int op_idx=0;
    long long current_num=0;
    bool has_digits=false;
    for(int i=0;i<temp.size();i++)
    {
        if(isdigit(temp[i]))
        {
            current_num=current_num*10+(temp[i]-'0');
            has_digits=true;
        }
        else if(temp[i]!='#')
        {
            nums[num_idx++]=current_num;
            current_num=0;
            ops[op_idx++]=temp[i];
        }
    }
    if(has_digits)
    {
        nums[num_idx++]=current_num;
    }
    for(int i=0;i<op_idx;i++)
    {
        if(ops[i]=='*')
        {
            nums[i+1]=nums[i]*nums[i+1];
            nums[i]=0;
            if(i>0&&ops[i-1]=='-')
            {
                ops[i]='-';
            }
            else
            {
                ops[i]='+';
            }
        }
    }
    long long res=num_idx>0?nums[0]:0;
    for(int i=0;i<op_idx;i++)
    {
        if(ops[i]=='+')
        {
            res+=nums[i+1];
        }
        else if(ops[i]=='-')
        {
            res-=nums[i+1];
        }
    }
    return res;
}
void rec(int idx, string& num, int target)
{
    if(idx>=num.size())
    {
        //calculate num now..if it returns target store it in answer;
        if(value_finder(num)==target)
        {
            string check="";
            for(int i=0;i<num.size();i++)
            {
                if(num[i]!='#')
                {
                    check+=num[i];
                }
            }
            bool invalid=false;
            int n=check.size();
            for(int i=0;i<n;i++)
            {
                if(isdigit(check[i]))
                {
                    if(check[i]=='0'&&(i+1<n&&isdigit(check[i+1])))
                    {
                        if(i==0||(!isdigit(check[i-1])))
                        {
                            invalid=true;
                            break;
                        }
                    }
                }
            }
            if(!invalid)
            {
                ans.push_back(check);
            }
        }
        return;
    }
    num[idx]=operations[0];
    rec(idx+2,num,target);
    num[idx]=operations[1];
    rec(idx+2,num,target);
    num[idx]=operations[2];
    rec(idx+2,num,target);
    num[idx]='#';
    rec(idx+2,num,target);
}
    vector<string> addOperators(string num, int target) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ans.clear();
        if(num.empty())
        {
            return ans;
        }
        string temp="";
        for(int i=0;i<num.size();i++)
        {
            temp+=num[i];
            if(i!=(num.size()-1))
            {
                temp+='#';
            }
        }
        rec(1,temp,target);
        return ans;
    }
};