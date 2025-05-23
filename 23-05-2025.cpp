class Solution {
public:
    int backtrack(int i, int sum, int m, int n, int x, vector<vector<int>>& dp) {
        if (i == n) return sum == x;
        if (dp[i][sum] != -1) return dp[i][sum];

        int ways = 0;
        for (int j = 1; j <= m; j++) {
            if (sum+j <= x) {
                ways += backtrack(i + 1, sum + j, m, n, x, dp);
            }
        }
        return dp[i][sum] = ways;
    }

    int noOfWays(int m, int n, int x) {
        vector<vector<int>> dp(n, vector<int>(x+1, -1));
        return backtrack(0, 0, m, n, x, dp);
    }
};
