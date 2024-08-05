class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int n = p.size();
        int res = 0;
        int cur = 0;
        sort(p.begin(), p.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
            });
        
        for (int i = 0; i < n; i++) {
            int x1 = p[i][0], y1 = p[i][1];
            int curY = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                int x2 = p[j][0], y2 = p[j][1];
                if (y2 > y1) continue;
                if (y2 > curY) {
                    res++;
                    curY = y2;
                }
            }
        }

        return res;
    }
};
