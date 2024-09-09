class Solution {
public:
    void solve(int col,vector<string> &board, vector<vector<string>>& ans,vector<int>&leftrow, vector<int>& ud,
    vector<int> &ld, int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }

        for (int row=0;row<n; row++)
        {
            if(leftrow[row]==0 && ld[row+col]==0 && ud[n-1+col-row]==0)
            {
                board[row][col] = 'Q';
                leftrow[row]=1;
                ld[row+col]=1;
                ud[n-1+col-row]=1;
                solve(col+1, board,ans, leftrow,ud, ld,n);
                board[row][col] = '.';
                leftrow[row]=0;
                ld[row+col]=0;
                ud[n-1+col-row]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for (int i=0;i<n;i++)
        {
            board[i]=s;
        }
        //upperdiggonal: ud
        //lowerdiagonal: ld
        vector<int> leftrow(n,0), ud(2*n -1, 0), ld(2*n-1, 0);
        solve(0, board,ans, leftrow,ud, ld,n);
        return ans;

    }
};
