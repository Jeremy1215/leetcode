class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        int midOne = 0;
        int oneOnes = 0;
        int oneZeros = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            int u = 0, d = m - 1;
            while (u <= d) {
                int ones = 0;
                if (u == d && l == r) {
                    midOne = grid[u][l];
                    break;
                }
                else if (u == d) {
                    ones = grid[u][l] + grid[u][r];
                    oneOnes += (ones == 2);
                    oneZeros += (ones == 1);
                    res += min(ones, 2 - ones);
                }
                else if (l == r) {
                    ones = grid[u][l] + grid[d][l];
                    oneOnes += (ones == 2);
                    oneZeros += (ones == 1);
                    res += min(ones, 2 - ones);
                }
                else {
                    ones = grid[u][l] + grid[u][r] + grid[d][l] + grid[d][r];
                    res += min(ones, 4 - ones);
                }
                u++;
                d--;
            }
            l++;
            r--;
        }

        if (midOne == 1) res++;
        
        if (oneOnes % 2 == 1 && oneZeros == 0) res+=2;

        return res;
    }
};
