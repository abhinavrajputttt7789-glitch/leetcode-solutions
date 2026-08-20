class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') //boundaries check grid se bhar to ni 
            return;

        grid[i][j] = '0';   //visit (convert the land into water)

        dfs(i + 1, j, n, m, grid); // down
        dfs(i - 1, j, n, m, grid); // up
        dfs(i, j + 1, n, m, grid); // right
        dfs(i, j - 1, n, m, grid); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();//size 
        int m = grid[0].size(); //size

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') { //check if jo b h wo agar land h to count kro and dfs call krdo
                    ans++;
                    dfs(i, j, n, m, grid);
                }
            }
        }

        return ans;
    }
};