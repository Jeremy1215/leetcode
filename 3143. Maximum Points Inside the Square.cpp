class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = s.size();
        vector<pair<vector<int>, char>> p;
        for (int i = 0; i < n; i++) {
            p.push_back({points[i], s[i]});
        }

        sort(p.begin(), p.end(), [](auto& a, auto& b) {
            return max(abs(a.first[0]), abs(a.first[1])) < max(abs(b.first[0]), abs(b.first[1]));
        });

        int maxR = 0;
        int res = 0;
        int group = 0;
        unordered_set<char> us;
        for (int i = 0; i < n; i++) {
            int x = p[i].first[0], y = p[i].first[1];
            int r = max(abs(x), abs(y)); 
            if (r > maxR) {
                maxR = r;
                res += group;
                group = 0;
            }
            group++;
            if (us.find(p[i].second) != us.end()) {
                return res;
            }
            
            //cout << x << " " << y << endl;
            
            us.insert(p[i].second);
            
            
        }
        res += group;

        return res;
    }
};
