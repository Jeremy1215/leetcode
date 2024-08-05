class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> parent(n, 0);
        vector<int> rank(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        int step = n - 1;
        vector<int> res;
        for (auto& q: queries) {
            int x = q[0], y = q[1];
            for (int i = y-1; i > x; i--) {
                if (find(parent, x) == find(parent, i)) break;
                unionByRank(parent, rank, x, i);
                step--;
            }
            for (int i = x+1; i < y; i++) {
                if (find(parent, x) == find(parent, i)) break;
                unionByRank(parent, rank, x, i);
                step--;
            }
            res.push_back(step);
        }

        return res;
    }

    int find(vector<int>& parent, int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    void unionByRank(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xParent = find(parent, x);
        int yParent = find(parent, y);

        if (xParent == yParent) return;

        if (rank[x] == rank[y]) {
            parent[yParent] = xParent;
            rank[x]++;
        }
        else if (rank[x] > rank[y])
            parent[yParent] = xParent;
        else
            parent[xParent] = yParent;
    }
};
