class Solution {
public:
    // int finans=0;
    // int rec(int i,int j, int n, int m, vector<vector<int>>& grid, int val)
    // {
    //     if(i==n && j==m)
    //     {
    //         //it means we have reached our destination and then we can proceed to follow a path which collides maximum with the second one, i guess running only one path is enough, then for that path we can automatically find the cells which can be shared, it will be shared if it is only 
    //         //it will check any linear path which has maximum sum and will return that only, simple
    //         //so my target is maximum linear path, not maximum total sum path, but maximum linear path
    //         finans=max(finans,val);
    //         return 0;
    //     }

    //     int ans=0;
    //     //it can move either down or right
    //     //if current move is down
    //     finans=max(finans,val)

        
        
        
    // }
    int maxScore(vector<vector<int>>& grid) {
        //so this a dp problem clearly
        //initially the value of answer is 0 (when no shared cells)
        //we want maximum value of shared cells
        // int ans= rec(0,0,grid.size(),grid[0].size(),0);

        //yeah the same approach i thought during the contest, but was diverted due to dp approach but later i saw a person's solution using same approach, he directly did it using the prefix sum (yeah...obviously the best choice which i couldn't think during contest)

        int m=grid.size(),n=grid[0].size();
        int ans=INT_MIN;
        for(int i=0;i<m;i++)
        {
            vector<int>pfx(n+1,0);
            for(int j=0;j<n;j++)pfx[j+1]=pfx[j]+grid[i][j];
            for(int j=0;j<n;j++)
            {
                for(int k=j;k<n;k++)
                {
                    int sum=pfx[k+1]-pfx[j];
                    int len=k-j+1;
                    if(len>=2)ans=max(ans,sum);
                    else if(len==1)
                    {
                        if(i>0 && i<m-1 && j>0 && j<n-1)ans=max(ans,sum);
                    }
                }
            }
        }

      for(int j=0;j<n;j++)
      {
        vector<int>pfx(m+1,0);
        for(int i=0;i<m;i++)pfx[i+1]=pfx[i]+grid[i][j];
          for(int i=0;i<m;i++)
          {
              for(int k=i;k<m;k++)
              {
                  int sum=pfx[k+1]-pfx[i];
                  int len=k-i+1;
                  if(len>=2)ans=max(ans,sum);
                  else if(len==1)
                  {
                      if(i>0 && i<m-1 && j>0 && j<n-1)ans=max(ans,sum);
                  } 
              }
          }
       }
       return ans;        
    }
};