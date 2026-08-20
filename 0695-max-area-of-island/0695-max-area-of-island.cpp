class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) //boundaries check grid se bhar to ni 
            return 0;

        grid[i][j] = 0;   //visit (convert the land into water)

        return 1
            + dfs(i+1, j, n, m, grid)
            + dfs(i-1, j, n, m, grid)
            + dfs(i, j+1, n, m, grid)
            + dfs(i, j-1, n, m, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();//size 
        int m = grid[0].size(); //size

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) { //check if jo b h wo agar land h to count kro and dfs call krdo
                    ans=max(ans,dfs(i,j,n,m,grid));

                }
            }
        }

        return ans;
    }
};