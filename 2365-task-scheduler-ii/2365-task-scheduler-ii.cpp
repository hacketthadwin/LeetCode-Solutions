class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<int,long long>mp;  //stores when the next same task need to be performed
        long long global_time=0;
        for(int i=0;i<tasks.size();i++)
        {
            if(mp.count(tasks[i]))
            {
                //perform if the space is satisfied
                global_time+=(long long)max(0LL,(long long)mp[tasks[i]]-global_time);
            }
            mp[tasks[i]]=(long long)global_time+space+1;
            global_time++;
        }
        return global_time;
    }
};