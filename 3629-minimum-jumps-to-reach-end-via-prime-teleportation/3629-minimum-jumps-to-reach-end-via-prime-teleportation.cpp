class Solution {
public:
    vector<int> buildSPF(int M) {
        vector<int> spf(M+1);
        iota(spf.begin(), spf.end(), 0);
        for(int i=2;i*i<=M;++i) 
        {
            if(spf[i]==i) 
            {
                for(int j=i*i;j<=M;j+=i)if(spf[j]==j) spf[j]=i;
            }
        }
        return spf;
    }

    unordered_map<int,vector<int>> buildTeleport(vector<int>& nums, vector<int>& spf) 
    {
        unordered_map<int,vector<int>> tele;
        vector<int> facs;
        for(int i=0;i<nums.size();++i) 
        {
            int x=nums[i];
            while(x>1) 
            {
                int p=spf[x];
                facs.push_back(p);
                while(x%p==0) x/=p;
            }
            for(int p:facs) tele[p].push_back(i);
            facs.clear();
        }
        return tele;
    }
    const int INF=1e9;
    int minJumps(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<=1) return 0;
        int M=*max_element(nums.begin(),nums.end());
        vector<int> spf=buildSPF(M);
        unordered_map<int,vector<int>> tele=buildTeleport(nums,spf);
        vector<int> dp(n,INF),inq(n,false);
        deque<int> q;
        dp[0]=0;
        q.push_back(0);
        inq[0]=true;
        while(!q.empty()) 
        {
            int i=q.front();
            q.pop_front();
            inq[i]=false;
            int d=dp[i];
            if(i-1>=0 && dp[i-1]>d+1) 
            {
                dp[i-1]=d+1;
                if(!inq[i-1]) 
                {
                    inq[i-1]=true;
                    q.push_back(i-1);
                }
            }
            if(i+1<n && dp[i+1]>d+1) 
            {
                dp[i+1]=d+1;
                if(!inq[i+1]) 
                {
                    inq[i+1]=true;
                    q.push_back(i+1);
                }
            }
            int v=nums[i];
            auto it=tele.find(v);
            if(it!=tele.end()) 
            {
                for(int j:it->second) 
                {
                    if(dp[j]>d+1) 
                    {
                        dp[j]=d+1;
                        if(!inq[j]) 
                        {
                            inq[j]=true;
                            q.push_back(j);
                        }
                    }
                }
                tele.erase(it);
            }
        }
        return dp[n-1]==INF?-1:dp[n-1];
    }
};
