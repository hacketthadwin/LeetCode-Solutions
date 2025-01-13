class Solution {
public:
//this is classic dfs problem,  we just find the number of groups possible, that denotes the number of stones remaining after deletion
//so we take one stone and explore all its row and column and include it in one group 
//and then for answer i delete the number of remaining stones from total number of stones
void dfs(vector<int>&visited,vector<vector<int>>& stones,int index)
{
    visited[index]=1;
    for(int i=0;i<visited.size();i++)
    {
        int row=stones[i][0];
        int col=stones[i][1];
        if(visited[i]==0 && (stones[index][0]==row || stones[index][1]==col))
        {
            dfs(visited,stones,i);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int groups=0;
        vector<int>visited(stones.size(),0);
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==1)continue;
            dfs(visited,stones,i);
            groups++;
        }
        return (stones.size()-groups);
        
    }
};