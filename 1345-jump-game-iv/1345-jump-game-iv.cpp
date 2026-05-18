class Solution {
public:
    // int rec(int idx,vector<int>& arr,map<int,vector<int>>&mp)
    // {
    //     //base case
    //    if(idx==arr.size())return 0;
    //    vector<int>curr_val=mp[arr[idx]];
    //    int steps=INT_MAX;
    // //    if(curr_val.back()==idx)
    // //    {
    //         //then we have 2 option, either we can go ahead or we can check the back value if it has any value which can be jumped, but nah, what if its back don't have any, but its back back has any, or back back back has any...so i cannot directly use it, i have to check if any value between current, or or or, i have option, why not i go from current to last index and will check for all, like i will keep increasing the steps as i go and i will jump to its last value
    // //    }

    //     for(int i=idx;i<arr.size();i++)
    //     {
            
    //     }
    // }
    int minJumps(vector<int>& arr) {
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        // return rec(0,arr,mp);

        //this is one of the question which teaches you art of leaving the problem instead of trying to keep correcting your code
        //one of the conditions for Dynamic programming is that the topological ordering must exists which means that there should not be any cycles. 
        //however, in this case, because of the back edges, there is a cycle. 
        //therefore, DP cannot be used. However , DP can be used but it will not be efficient.
    
        //now when i will need to jump to j, i will just access things using map and then jump to that 
        
        //THIS WAS A GOOD QUESTIONS IMO, EVEN THOUGH PEOPLE IN DISCUSSIONS FOUND IT EASY....
        //WE SHOULDN'T NEED TO MAKE THE ADJACENCY LIST IN THIS GRAPH BECAUSE IT CAN ALSO BECOME COMPLETE GRAPH i.e. 
        //(5*10^4)^2 which is unable to store and gives MLE
        //i made few mistakes during writing of code, i.e. overall idea of increasing the count after processing complete current batch of queue and always mark visited during pushing element, not during pop, therefore we dont even need to check the visited during pop, it gives error, so learn, mark visited during push ( i know i just keep forgetting and obviously we cannot have much time to think of this during contest)
        queue<pair<int,int>>q;
        q.push({arr[0],0});
        vector<bool>visited(arr.size(),false);
        visited[0]=true;
        int count=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int num=q.front().first;
                int idx=q.front().second;
                q.pop();
                if(idx==arr.size()-1)
                {
                    return count;
                }
                for(auto m:mp[num])
                {
                    if(visited[m])continue;
                    visited[m]=true;
                    q.push({num,m});
                }
                mp[num].clear();
                if(idx-1>=0 && !visited[idx-1])
                {
                    q.push({arr[idx-1],idx-1});
                    visited[idx-1]=true;
                }
                if(idx+1<arr.size() && !visited[idx+1])
                {
                    q.push({arr[idx+1],idx+1});
                    visited[idx+1]=true;
                }
            }
            count++;
        }
        return count;
    }
};