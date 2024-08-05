class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int left = ceil(sqrt(l));
        int right = sqrt(r) + 1;
        int res = r - l + 1;
        for (int i = left; i < right; i++) {
            if (isPrime(i)) {
                res--;
            }
        }

        return res;
        
    }

    bool isPrime(int n) {
        if (n == 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};
