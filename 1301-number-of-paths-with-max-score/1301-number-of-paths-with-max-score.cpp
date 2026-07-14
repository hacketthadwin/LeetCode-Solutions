class Solution {
public:

    int dp(int i,int j,int n,int m,vector<string>& board,vector<vector<int>>&rec1)
    {
        if((i==n-1) && (j==m-1))
        {
            return 0;
        }
        if(rec1[i][j]!=-1)return rec1[i][j];
        int ans=INT_MIN;
        if(i+1<n && board[i+1][j]!='X' )ans=max(ans,(board[i][j]-'0')+dp(i+1,j,n,m,board,rec1));
        if(j+1<m && board[i][j+1]!='X')ans=max(ans,(board[i][j]-'0')+dp(i,j+1,n,m,board,rec1));
        if(i+1<n && j+1<m && board[i+1][j+1]!='X')ans=max(ans,(board[i][j]-'0')+dp(i+1,j+1,n,m,board,rec1));
        return rec1[i][j]=ans;
        
    }
    const int mod=1e9+7;
    int dp2(int i,int j,int val,int n,int m,vector<string>& board,vector<vector<vector<int>>>&rec2)
    {
        if((i==n-1) && (j==m-1))
        {
            if(val==0)
            {
                return 1;
            }
            return 0;
        }
        if(rec2[i][j][val]!=-1)return rec2[i][j][val];
        int ans=0;
        if(i+1<n && (board[i+1][j]!='X') && (val-(board[i][j]-'0')>=0))ans=(ans+dp2(i+1,j,(val-(board[i][j]-'0')), n, m, board,rec2))%mod;
        if(j+1<m &&( board[i][j+1]!='X') && (val-(board[i][j]-'0')>=0))ans=(ans+dp2(i,j+1,(val-(board[i][j]-'0')) ,n,m,board,rec2))%mod;
        if(i+1<n && j+1<m && (board[i+1][j+1]!='X') && (val-(board[i][j]-'0')>=0))ans=(ans+dp2(i+1,j+1, (val-(board[i][j]-'0')),n,m,board,rec2))%mod;
        return rec2[i][j][val]=ans;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>>rec1(n+4,vector<int>(m+4,-1));
        int max_val=dp(0,0,n,m,board,rec1)-('E'-'0');
        // return {max_val,max_val};
        if(max_val<0)return {0,0};
        vector<vector<vector<int>>>rec2(n+4,vector<vector<int>>(m+4,vector<int>(max_val+('E'-'0')+5,-1)));
        int cnt_path=dp2(0,0,max_val+('E'-'0'),n,m,board,rec2);
    return {max_val,cnt_path};


    }
};