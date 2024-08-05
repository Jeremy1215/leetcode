class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});
        
        long long res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < right; i++) {
            auto p = pq.top();
            pq.pop();
            if (i >= left - 1)
                res = (res + p.first) % mod;
            if (++p.second < n) {
                // p.second++;
                p.first += nums[p.second];
                
                pq.push(p);
            }
        }

        return res;
    }
};
