class unionfind{
    private:vector<int>p,rank;
    public:
    unionfind(int n)
    {
        rank.assign(n,0);p.assign(n,0);
        iota(p.begin(),p.end(),0);
    }
    int find_set(int i){return (p[i]==i) ? i : p[i]=find_set(p[i]);}
    bool is_same_set(int i,int j){return find_set(i)==find_set(j);}
    void union_set(int i,int j){
        if(!is_same_set(i,j))
        {
            int x=find_set(i),y=find_set(j);
            if(rank[x]>rank[y])p[y]=x;
            else
            {
                p[x]=y;
                if(rank[x]==rank[y])rank[y]++;
            }
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //so basically i will need to connect u to v..but then i also need to ensure that the edge i connect isn't already connected...that is one of the components
        // i.e. if both u and v already have same parents...then i will not join them..as they are already connected that's all
        int n=1;
        for(int i=0;i<edges.size();i++)
        {
            n=max(n,edges[i][0]);
            n=max(n,edges[i][1]);
        }
        unionfind DSU(n+1);
        vector<int>ans;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            if(DSU.find_set(u)==DSU.find_set(v))
            {   
                ans.push_back(u);
                ans.push_back(v);
                break;
            }
            DSU.union_set(u,v);
        }

        return ans;



    }
};