class Solution {
private: 
    int solve(vector<vector<int>>& grid,int i,int j, vector<vector<int>>& dp){
        if(i==0 && j==0){
            dp[i][j]=grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else if(i>0 && j>0){
            dp[i][j]= grid[i][j]+ min(solve(grid,i-1,j,dp),solve(grid,i,j-1,dp));
        }
        else if(i>0 && j==0){
            dp[i][j]= grid[i][j] + solve(grid,i-1,j,dp);
        }
        else if(j>0 && i==0){
            dp[i][j]= grid[i][j] + solve(grid,i,j-1,dp);
        } 
        return dp[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(grid,m-1,n-1,dp);
    }
};
