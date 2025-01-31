class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        int numR = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if (!st.empty()) {
                    st.pop();
                }
                else {
                    numR++;
                }
            }
        }

        int numL = st.size();
        return numL + numR;
    }
};
