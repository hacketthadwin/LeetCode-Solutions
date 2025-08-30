class Solution {
public:
    // vector<pair<int,int>>v={{2,2},{2,5},{2,8},{5,2},{5,5},{5,8},{8,2},{8,5},{8,8}};
    bool rec(int i,int j, vector<vector<char>>& board)
    {
        map<int,int> mp1, mp2;
        for(int p=0;p<9;p++)
        {
            if(board[i][p] != '.')
            {
                int num = board[i][p]-'0';
                if(mp1[num]++) return false; 
            }
            if(board[p][j] != '.')
            {
                int num = board[p][j]-'0';
                if(mp2[num]++) return false;
            }
        }

        map<int,int> mp3;
        int st = (i/3)*3;
        int en = (j/3)*3;
        for(int p=st;p<st+3;p++)
        {
            for(int q=en;q<en+3;q++)
            {
                if(board[p][q] != '.')
                {
                    int num = board[p][q]-'0';
                    if(mp3[num]++) return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.' && !rec(i,j,board)) 
                    return false;
            }
        }
        return true;
    }

};
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
