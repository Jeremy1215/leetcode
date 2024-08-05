class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int b = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b')
                b++;
            else {
                res = min(res + 1, b);
            }
        }
        return res;
    }
};

// b left:  00112334

// a right: 43322210
