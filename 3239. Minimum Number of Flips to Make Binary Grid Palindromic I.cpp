class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int resRow = 0;
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1;
            while (l < r) {
                if (grid[i][l] != grid[i][r]) resRow++;
                l++;
                r--;
            }
        }

        int resCol = 0;
        for (int j = 0; j < n; j++) {
            int u = 0, d = m - 1;
            while (u < d) {
                if (grid[u][j] != grid[d][j]) resCol++;
                u++;
                d--;
            }
        }

        return min(resRow, resCol);
    }
};
