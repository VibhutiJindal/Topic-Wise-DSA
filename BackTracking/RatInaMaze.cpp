// Rat in a maze problem
//Problem Link : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// User function template for C++
class Solution {
    void solve(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string move,
               vector<vector<int>> &vis, int di[], int dj[]) {
        if(i == n-1 && j == n-1) {
            ans.push_back(move);
            return;
        }
        
        string dir = "DLRU";
        for(int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && mat[nexti][nextj] == 1) {
                vis[i][j] = 1;
                solve(nexti, nextj, mat, n, ans, move + dir[ind], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }
    
public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0)); // Corrected typo here
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if(mat[0][0] == 1) // Corrected the variable name from 'm' to 'mat'
            solve(0, 0, mat, n, ans, "", vis, di, dj);
        return ans;
    }
};

