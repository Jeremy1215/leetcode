class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> distance(n, 0);
        vector<vector<int>> from(n);
        for (int i = 0; i < n; i++) {
            distance[i] = i;
            from[i].push_back(i-1);
        }

        vector<int> res;
        for (auto& q: queries) {
            int u = q[0], v = q[1];
            from[v].push_back(u);
            if (distance[u] + 1 < distance[v]) {
                distance[v] = distance[u] + 1;
                for (int i = v+1; i < n; i++) {
                    for (auto f: from[i])
                        distance[i] = min(distance[i], distance[f] + 1);
                }
            }
            res.push_back(distance[n-1]);
        }

        return res;
    }
};
