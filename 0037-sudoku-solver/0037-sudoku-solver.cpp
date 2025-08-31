class Solution {
public:
vector<vector<char>>b;
bool valid(int i,int j,char c,vector<vector<char>> board)
{
    for(int m=0;m<9;m++)
    {
        if(board[m][j]==c)return false;
        if(board[i][m]==c)return false;
        if(board[3*(i/3)+m/3][3*(j/3)+m%3]==c) return false;//checking the diagonal is the toughest step in the problem just like in n queens problem it was and also the error i was getting because i forgot to add ==c
    }
    return true;
}
    bool rec(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(valid(i,j,c,board))
                        {
                            board[i][j]=c;
                            if(rec(board)==true)
                            {
                                return true;
                            }
                            else
                            {
                                 board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        rec(board);
        
    }
};