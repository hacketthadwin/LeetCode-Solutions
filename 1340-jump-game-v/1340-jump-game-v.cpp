// class Solution {
// public:
//     int maxJumps(vector<int>& arr, int d) {
//         //so i guess i can solve this one using the same bfs method by which i solved it initially
//         int ans=0;
//         for(int i=0;i<arr.size();i++)
//         {
//             queue<pair<int,int>>q;
//             q.push({i,1});
//             // vector<bool>visited(arr.size(),false);
//             // visited[i]=true;
//             // int cnt=0;
//             while(!q.empty())
//             {
//                 // cnt++;
//                     int curr_i=q.front().first;
//                     int cnt=q.front().second;
//                     q.pop();
//                     ans=max(ans,cnt);
//                     for(int j=1;j<=d;j++)
//                     {
//                         if(curr_i-j>=0)
//                         {
//                             if(arr[curr_i-j]<arr[curr_i])
//                             {
//                                 //correct, so can be pushed into queue
//                                 // if(!visited[curr_i-j])
//                                 // {
//                                         q.push({curr_i-j,cnt+1});
//                                         // visited[curr_i-j]=true;
//                                 // }
//                             }
//                             else
//                             {
//                                 break;
//                             }
//                         }
//                     }
//                     for(int j=1;j<=d;j++)
//                     {
//                         if(curr_i+j<arr.size())
//                         {
//                             if(arr[curr_i]>arr[curr_i+j])
//                             {
//                                 //correct, so can be pushed into queue
//                                 // if(!visited[curr_i+j])
//                                 // {
//                                         q.push({curr_i+j,cnt+1});
//                                         // visited[curr_i+j]=true;
//                                 // }
//                             }
//                             else
//                             {
//                                 break;
//                             }
//                         }
//                     }
//             }
            
//         }

//         return ans;
//     }
// };

//THE BELOW ONE IS WRONG, THE ABOVE ONE IS CORRECT BUT GAVE TLE, SO I NEED OPTIMISATION AND THE OPTIMISATION WHAT I SEE IS IF I CONVERT THE ABOVE ONE INTO DFS AND THEN APPLY MEMOISATION, THAT SHOULD WORK IG
// class Solution {
// public:
//     int maxJumps(vector<int>& arr, int d) {
//         //so i guess i can solve this one using the same bfs method by which i solved it initially
//         int ans=0;
//         for(int i=0;i<arr.size();i++)
//         {
//             queue<int>q;
//             q.push(i);
//             vector<bool>visited(arr.size()+1,false);
//             visited[i]=true;
//             int cnt=0;
//             while(!q.empty())
//             {
//                 cnt++;
//                 int sz=q.size();
//                 for(int i=0;i<sz;i++)
//                 {
//                     int curr_i=q.front();
//                     q.pop();
//                     for(int j=1;j<=d;j++)
//                     {
//                         if(curr_i-j>=0 && !visited[curr_i-j])
//                         {
//                             if(arr[curr_i-j]>arr[curr_i])
//                             {
//                                 //correct, so can be pushed into queue
//                                 q.push(curr_i-j);
//                                 visited[curr_i-j]=true;
//                             }
//                             else
//                             {
//                                 break;
//                             }
//                         }
//                     }
//                     for(int j=1;j<=d;j++)
//                     {
//                         if(curr_i+j<arr.size() && !visited[curr_i+j])
//                         {
//                             if(arr[curr_i]>arr[curr_i+j])
//                             {
//                                 //correct, so can be pushed into queue
//                                 q.push(curr_i+j);
//                                 visited[curr_i+j]=true;
//                             }
//                             else
//                             {
//                                 break;
//                             }
//                         }
//                     }
//                 }


//             }

//             ans=max(ans,cnt);
            
//         }

//         return ans;
//     }
// };


class Solution {
public:
int dp[1001];
    int dfs(int curr_i,vector<int>& arr, int d)
    {
        if (dp[curr_i]!=0)return dp[curr_i];
        int ans=1;
                    for(int j=1;j<=d;j++)
                    {
                        if(curr_i-j>=0)
                        {
                            if(arr[curr_i-j]<arr[curr_i])
                            {
                                //correct, so can be pushed into queue
                                ans=max(ans,1+dfs(curr_i-j,arr,d));
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    for(int j=1;j<=d;j++)
                    {
                        if(curr_i+j<arr.size())
                        {
                            if(arr[curr_i]>arr[curr_i+j])
                            {
                                //correct, so can be pushed into queue
                                ans=max(ans,1+dfs(curr_i+j,arr,d));
                            }
                            else
                            {
                                break;
                            }
                        }
                    }

                    return dp[curr_i]=ans;

    }
    int maxJumps(vector<int>& arr, int d) {
        memset(dp,0,sizeof(dp));  //0 because our minimum answer would be 1
        int finans=1;
        for(int i=0;i<arr.size();i++)
        {
            finans=max(finans,dfs(i,arr,d));
        }
        return finans;
    }
};