class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if (r>n) return 0;
        if (r>(n-r)) r = n-r;
        long long res = 1;
        for (int i=1; i<=r; i++) {
            res *= (n-i+1);
            res /= i;
        } return res;
    }
};
