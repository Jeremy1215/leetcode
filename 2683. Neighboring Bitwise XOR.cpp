class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        bool cur = 0; // oringinal[0]
        for (int i = 0; i < n; i++) {
            if (derived[i] == 1)
                cur ^= 1; // cur = cur xor 1
        }
        if (cur == 0) return true;
        return false;
    }
};
