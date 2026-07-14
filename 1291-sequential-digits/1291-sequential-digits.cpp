class Solution {
public:
    bool is_valid(string check,string lower,string higher)
    {
        int int_check=stoi(check);
        int int_lower=stoi(lower);
        int int_higher=stoi(higher);
        if(int_check>=int_lower && int_check<=int_higher)return true;
        return false;
    }
    vector<int> sequentialDigits(int low, int high) {
            string lower=to_string(low);
            string higher=to_string(high);
            string s=lower;
            string t="123456789";
            //this s will be moving forward

            //so basically this will move from len of low to len of high
            // now for each index in that
            
            // so basically according to val we are going to move in t
            //this becomes sliding window problem now...that is we are going to take all possible values from val index till either it becomes end of t..or the first value becomes more than the higher
            vector<string>temp_ans;
            for(int i=lower.size();i<=higher.size();i++)
            {
                //the i here denotes the window size
                for(int k=0;k<t.size()-i+1;k++)
                {
                    //i will form all string continously and whenever the string dissatifies 
                    string check=t.substr(k,i);
                    if(is_valid(check,lower,higher))
                    {
                        temp_ans.push_back(check);
                    }
                }
            }
            vector<int>ans;
            for(auto temp:temp_ans)
            {
                ans.push_back(stoi(temp));
            }
            return ans;        

    }
};