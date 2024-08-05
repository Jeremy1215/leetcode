class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> balls(n, vector(11, 0));
        for (int i = 0; i < pick.size(); i++) {
            balls[pick[i][0]][pick[i][1]]++;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 11; j++) {
                if (balls[i][j] > i) {
                    res++;
                    break; 
                }
            }
        }

        return res;
    }
};
