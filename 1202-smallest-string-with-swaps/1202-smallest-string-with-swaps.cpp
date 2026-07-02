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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //so basically i can swap any characters in a component which is made by indices connected with pairs..that's all..
        //just find connected components..just find all characters in the group..then we can choose the minimum character of the group for each index...easy (but not if i didn't knew unionfind before)

        unionfind DSU(s.size());
        for(int i=0;i<pairs.size();i++)
        {
            int u=pairs[i][0];
            int v=pairs[i][1];

            DSU.union_set(u,v);
        }

        map<int,vector<char>>idx_chars;
        map<int,vector<int>>idx_idx;
        for(int i=0;i<s.size();i++)
        {
            idx_chars[DSU.find_set(i)].push_back(s[i]);
            idx_idx[DSU.find_set(i)].push_back(i);
        }
        string ans=s;
        for(auto m:idx_chars)
        {
            int par=m.first;
            vector<char>chars=m.second;
            vector<int>idxs=idx_idx[m.first];

            sort(chars.begin(),chars.end());
            sort(idxs.begin(),idxs.end());
            for(int i=0;i<chars.size();i++)
            {
                ans[idxs[i]]=chars[i];
            }
        }
        return ans;
    }
};