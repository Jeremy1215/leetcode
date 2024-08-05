class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        unordered_map<string, int> um;
        for (int i = 0; i < n; i++) {
            um[arr[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (um[arr[i]] == 1) k--;
            if (k == 0) return arr[i];
        }

        return "";
    }
};
