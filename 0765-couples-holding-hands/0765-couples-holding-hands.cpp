class Solution {
public:
    map<int,int>mp;
    int rec(int idx, vector<int>& row)
    {
        if(idx>=row.size())
        {
            //check for whole whichever is not in right place..if everything is in right place..return ans, else return INT_MAX
            for(int i=0;i<row.size()-1;i++)
            {
                if(row[i]%2==1)
                {
                    //i need to check the lower one
                    if(i>0 && row[i-1]==row[i]-1)
                    {
                        continue;
                    }
                    else if(i<row.size()-1 && row[i+1]==row[i]-1)
                    {
                        continue;
                    }
                    else
                    {
                        return INT_MAX;
                    }
                }
                else
                {
                    if(i>0 && row[i-1]==row[i]+1)
                    {
                        continue;
                    }
                    else if(i<row.size()-1 && row[i+1]==row[i]+1)
                    {
                        continue;
                    }
                    else
                    {
                        return INT_MAX;
                    }
                }
            }
            return 0;
        }
        int num=row[idx];
        bool check_lower=false;
        if(num%2==1)
        {
            check_lower=true;
        }
        
    // since i am starting from idx 0 and always moving left to right, 
    // any number behind me (idx-1) is already fixed and paired up by previous steps.
    // also, because i skip 2 indices (idx+2) whenever a couple matches, i will always land on an even index.
    // this means idx-1 will always be a part of a completed couple that is already sorted.
    // so from the beginning, i never need to check or swap anything behind me
    // i only need to look at and fix the further one (idx+1).

            int temp_ans=INT_MAX;
            if(check_lower)
            {
                if(idx-1>=0 && row[idx-1]==num-1)
                {
                    //no need swapping...move one step ahead...
                    temp_ans=min(temp_ans,rec(idx+1,row));
                }
                else if(idx<row.size()-1 && row[idx+1]==num-1)
                {
                    //no need swapping...move 2 step ahead
                    temp_ans=min(temp_ans,rec(idx+2,row));
                }
                else
                {
                    //need swapping
                    //try swapping both left or right and check
                    if(idx<row.size()-1)
                    {
                        //no need swapping...move 2 step ahead
                        int old_idx = mp[num-1];
                        swap(row[idx+1],row[old_idx]);
                        mp[row[idx+1]]=idx+1;
                        mp[row[old_idx]]=old_idx;
                        
                        int next_res = rec(idx+2,row);
                        if(next_res != INT_MAX)
                        {
                            temp_ans=min(temp_ans,next_res+1);
                        }
                        
                        swap(row[idx+1],row[old_idx]);
                        mp[row[idx+1]]=idx+1;
                        mp[row[old_idx]]=old_idx;
                    }

                }
            }
            else
            {
                if(idx-1>=0 && row[idx-1]==num+1)
                {
                    //no need swapping...move one step ahead...
                    temp_ans=min(temp_ans,rec(idx+1,row));
                }
                else if(idx<row.size()-1 && row[idx+1]==num+1)
                {
                    //no need swapping...move 2 step ahead
                    temp_ans=min(temp_ans,rec(idx+2,row));
                    
                }
                else
                {
                    //need swapping
                    //try swapping both left or right and check
                    if(idx<row.size()-1)
                    {
                        //no need swapping...move 2 step ahead
                        int old_idx = mp[num+1];
                        swap(row[idx+1],row[old_idx]);
                        mp[row[idx+1]]=idx+1;
                        mp[row[old_idx]]=old_idx;
                        
                        int next_res = rec(idx+2,row);
                        if(next_res != INT_MAX)
                        {
                            temp_ans=min(temp_ans,next_res+1);
                        }
                        
                        swap(row[idx+1],row[old_idx]);
                        mp[row[idx+1]]=idx+1;
                        mp[row[old_idx]]=old_idx;
                    }
                }

            }

            return temp_ans;
        

    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();

        for(int i=0;i<row.size();i++)
        {
            mp[row[i]]=i;
        }
        return rec(0,row);
        //now i just need to make them side by side
        //i guess i can do it directly..like for each number i will have 2 choices..i can either put them in right or put them in left
    }
};