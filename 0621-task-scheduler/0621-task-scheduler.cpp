class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<int,int>freq;
        map<int,int>next_available;
        for(auto t:tasks)
        {
            int num=t-'A';
            freq[num]++;
            next_available[num]=0;
        }
        int global_time=0;
        while(!freq.empty())
        {
                map<int,set<pair<int,int>>>check;  // for each time...i will store all the available chars that are available in that moment and then i will choose the one with maximum freq...
                for(auto m:next_available)
                {

                    if(freq.count(m.first) && freq[m.first]>0)
                    {
                        check[max(0,m.second-global_time)].insert({freq[m.first],m.first});
                    }
                    
                }

                //now check contains the thing...now i will choose the first check element of map..because it will give me the lowest time..and from that i will choose the last element of set which will give me the highest freq element with that time

                auto it = check.begin();
                int key = it->first;          // the smallest key
                set<pair<int,int>>& st = it->second;    // the corresponding set
                int alphabet = (*st.rbegin()).second;
                global_time+=key;
                freq[alphabet]--;
                if(freq[alphabet]==0)
                {
                    freq.erase(alphabet);
                }
                next_available[alphabet]=global_time+n+1;
                global_time++;
        }

        return global_time;
        
    }
};

        // map<int,pair<int,int>>mp;
        // for(int i=0;i<tasks.size();i++)
        // {
        //     int alphabet=tasks[i]-'A';
        //     if(mp.count(alphabet))
        //     {
        //         int curr_cnt=mp[alphabet].first;
        //         mp[alphabet]={curr_cnt+1,0};
        //     }
        //     else
        //     {
        //         mp[alphabet]={1,0};
        //     }
        // }
        // //now how will i choose the one with minimum remaining cooldown is simply based on priority queue
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // //this priority queue will store first the cooldown..then the alphabet...so basically it is reversed sorted in order of cooldown...now if the alphabet count is still there...i will simply include it...else i will just pop the element from the priority queue
        // for(auto m:mp)
        // {
        //     pq.push({0,m.first});
        // }

        // //this means no element has currently any cooldown...the moment i use that element...it will have cooldown and its count gets decreased in the map
        // int cnt=0;
        // int curr_cooldown=0;
        // while(!pq.empty())
        // {
        //     pair<int,int>cooldown_alphabet=pq.top();

        //     int alphabet=cooldown_alphabet.second;
        //     int cooldown=mp[alphabet].second;
        //     //but but but...i also need to decrease the cooldown of all other element..so it will have a decrement function too

        //     pq.pop();
        //     cnt+=(cooldown + 1);
        //     mp[alphabet].first--;
        //     if(mp[alphabet].first==0)
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         pq.push({n,alphabet});
        //         mp[alphabet]={mp[alphabet].first,n};
        //         for(auto m:mp)
        //         {
        //             if(m.first!=alphabet)
        //             {
        //                 m.second.second--;
        //             }
        //         }
        //     }
        // }
        // return cnt;
        // //so it will store 2 things..count,cooldown remaining..and then it will choose the one with lowest cooldown

        // //so i will pick the one with lowest remaining cooldown period..simple

        //let's take a break and have thought process on this problem