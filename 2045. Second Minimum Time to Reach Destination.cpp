class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adjList(n);
        for (auto& edge: edges) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> visit(n, 0);
        vector<int> distance(n, -1);
        queue<pair<int, int>> q;
        q.push({0, 0});
        distance[0] = 0;

        while (!q.empty()) {
            auto [u, t] = q.front();
            q.pop();

            int tt = 0;
            int round = t / change;
            if (round % 2 == 0)
                tt = t + time;
            else
                tt = (round + 1) * change + time;

            for (auto v: adjList[u]) {
                if (visit[v] < 2 && distance[v] < tt) {
                    visit[v]++;
                    distance[v] = tt;
                    q.push({v, tt});
                }

                if (v == n - 1 && visit[v] == 2)
                    return tt;
            }
        }

        return -1;
    }
};
