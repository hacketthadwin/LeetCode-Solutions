class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<pair<int,int>> directions = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
        queue<pair<int,int>>q;
        int curr=0;
        q.push({0,0});
        while(!q.empty())
        {
            int curr_row=q.front().first;
            int curr_col=q.front().second;
            q.pop();
            curr++;
            bool found=false;
            for(int i=0;i<directions.size();i++)
            {
                int next_row=curr_row+directions[i].first;
                int next_col=curr_col+directions[i].second;
                if(next_row>=0 && next_col>=0  && next_col<grid[0].size() && next_row<grid.size() && grid[next_row][next_col]==(curr))
                {
                    q.push({next_row,next_col});
                    found=true;
                }
            }
            if(!found)return false;

            if(curr==(grid.size()*grid[0].size())-1)break;
        }
        return true;
    }
};