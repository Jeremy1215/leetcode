class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> um;
        for (auto& x: arr) {
            um[x]++;
        }

        for (auto& y: target) {
            if (um.find(y) == um.end())
                return false;
            um[y]--;
            if (um[y] == 0)
                um.erase(y);
        }

        return true;
    }
};
