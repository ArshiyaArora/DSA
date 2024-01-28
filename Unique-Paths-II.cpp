class Solution {
private:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;  // Invalid index, return 0
        }

        if (obstacleGrid[i][j] == 1) {
            return dp[i][j] = 0;
        }

        if (i == 0 && j == 0 && obstacleGrid[i][j] != 1) {
            return dp[i][j] = 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];  // Return memoized result if available
        }

        dp[i][j] = solve(obstacleGrid, i - 1, j, dp) + solve(obstacleGrid, i, j - 1, dp);
        return dp[i][j];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));  // Initialize with -1
        return solve(obstacleGrid, m - 1, n - 1, dp);
    }
};
