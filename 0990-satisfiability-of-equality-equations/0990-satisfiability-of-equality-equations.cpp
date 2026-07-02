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
    bool equationsPossible(vector<string>& equations) {
        unionfind DSU(500000);
        for(int i=0;i<equations.size();i++)
        {
            int ax=equations[i][0]-'a';
            int bx=equations[i][3]-'a';
            char possible=equations[i][1];
            if(possible=='=')
            {
                DSU.union_set(ax,bx);
            }
        }

        for(int i=0;i<equations.size();i++)
        {
            int ax=equations[i][0]-'a';
            int bx=equations[i][3]-'a';
            char possible=equations[i][1];
            if(possible!='=')
            {
                if(DSU.is_same_set(ax,bx))return false;
            }
        }

        return true;
    }
};