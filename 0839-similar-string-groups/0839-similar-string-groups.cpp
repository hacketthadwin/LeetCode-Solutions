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
    int numSimilarGroups(vector<string>& strs) {
        map<string,int>mp;
        map<int,string>pm;
        int curr=0;
        for(int i=0;i<strs.size();i++)
        {
            if(!mp.count(strs[i]))
            {
                mp[strs[i]]=curr;
                pm[curr]=strs[i];
                curr++;
            }
        }

        //initially all groups are seperate..i will match them only if i find each string as a part of some else group
        unionfind DSU(curr);
        for(int i=0;i<strs.size();i++)
        {
            
            for(int j=i+1;j<strs.size();j++)
            {
                int cnt=0;
                for(int k=0;k<strs[j].size();k++)
                {
                    if(strs[i][k]!=strs[j][k])
                    {
                        cnt++;
                    }
                }

                if(cnt<=2)
                {
                    //it means they are related...so i will join them
                    //so
                    DSU.union_set(mp[strs[i]],mp[strs[j]]);
                }
            }
        }
            int ans=0;
        for(int i=0;i<curr;i++)
        {
            if(DSU.find_set(i)==i)ans++;
        }

        return ans;

    }
};