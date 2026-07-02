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
vector<int> getPrimeFactors(int n)
{
    vector<int> factors;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            factors.push_back(i);   
            while(n % i == 0)      
                n /= i;
        }
    }
    if(n > 1) factors.push_back(n); 
    return factors;
}
    int largestComponentSize(vector<int>& nums) {
        unionfind DSU(100001);
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            vector<int>primes=getPrimeFactors(nums[i]);
            for(auto p:primes)
            {
                mp[p].push_back(nums[i]);
            }
        }
       for(auto m:mp)
       {
            vector<int>vals=m.second;
            for(int i=0;i<vals.size();i++)
            {
                DSU.union_set(vals[i],vals[0]); //we can connect either way i.e. with vals[i] to vals[i+1] or vals[0]
            }
       }
        map<int,int>cnt;
       for(int i=0;i<nums.size();i++)
       {
            int par=DSU.find_set(nums[i]);
            cnt[par]++;
       }
        int ans=0;
       for(auto c:cnt)
       {
        ans=max(ans,c.second);
       }
       return ans;
    }
};