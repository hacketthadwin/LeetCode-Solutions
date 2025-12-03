//THIS WAS GENIUNLY A TRICKY QUESTION

    class Solution {
    public:
    
    //first lets count the number of extra spaces present
    vector<int>give_cnt(int residual,int cnt)
    {
        if(cnt==0)return {};
        int div=residual/cnt;
        vector<int>ans(cnt,div);
        int modu=residual%cnt;
        int i=0;
        while(modu>0)
        {
            ans[i]++;
            modu--;
            i++;
        }
    
        return ans;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        vector<int>words_len(n);
        for(int i=0;i<n;i++)
        {
            words_len[i]=words[i].size();
        }
        //now we will count number of words in each line
        //then we will count the number of extra spaces(other than mandatory spaces) for each line
        vector<int>num; //this num will store number of words in each sentence
        vector<vector<int>>spaces; //for each sentence, this will store the number of extra spaces after each line (other than mandatory)
        for(int i=0;i<n;)
        {
            int cnt=0;
            int curr_len=0;
            //cnt will store number of words and curr_len will store the total length of sentence
            while((i<n)&&((curr_len + words_len[i] + (cnt>0?1:0)) <= maxWidth))  
            //this was where my understanding and code was giving bug, i thought that if i add space after every word,
            //then it will act same as checking 1 space before adding each new word,
            //but this is NOT same in the greedy condition. 
            //When we add space after the previous word, that space is counted only AFTER adding that word,
            //but the greedy check must consider the mandatory space BEFORE adding the next word.
            //Because of this timing difference, during the fit check, I was checking only (curr_len + word_len),
            //but the rule actually requires checking (curr_len + 1 + word_len) for every word except the first.
            //So my curr_len was not wrong, but my fitting condition was skipping this mandatory space,
            //which made me think "this fits", even though the real layout needs 1 more space.
            //That is why adding space after each word is NOT logically equivalent to requiring 1 space before each new word.
            {
                curr_len += words_len[i];
                if(cnt>0) curr_len += 1;
                cnt++;
                i++;
            }
            vector<int>extra_spaces(cnt-1,0); //these are spaces other than mandatory spaces
            extra_spaces=give_cnt(maxWidth-curr_len,cnt-1);
            num.push_back(cnt);
            spaces.push_back(extra_spaces);
        }

        //now processing will begin
        int k=0;
        vector<string>ans(num.size(),"");
        for(int i=0;i<num.size()-1;i++)
        {
            int words_in_line=num[i];
            vector<int>spaces_in_line=spaces[i];
            spaces_in_line.push_back(0);
            //single word handler
            if (words_in_line == 1) 
            {
                ans[i] += words[k];
                k++;
                ans[i] += string(maxWidth - ans[i].size(), ' ');
                continue;
            }

            for(int j=0;j<words_in_line;j++)
            {
                ans[i]+=words[k];
                if(j!=(words_in_line-1))ans[i]+=" ";
                for(int s=0;s<spaces_in_line[j];s++)
                {
                    ans[i]+=" ";
                }
                k++;
            }
        }

        int d=num.size()-1;
        int words_in_line=num[d];
        vector<int>spaces_in_line=spaces[d];
        spaces_in_line.push_back(0);
        if (words_in_line == 1) 
        {
            ans[d] += words[k];
            k++;
            ans[d] += string(maxWidth - ans[d].size(), ' ');
            return ans;
        }  
        for(int j=0;j<words_in_line;j++)
        {
            ans[d]+=words[k];
            if(j!=(words_in_line-1))ans[d]+=" ";
            k++;
        }

        ans[d] += string(maxWidth - ans[d].size(), ' ');

        return ans;

    }
};
