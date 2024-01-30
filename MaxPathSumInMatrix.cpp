#include <bits/stdc++.h> 

int solve(vector<vector<int>> &matrix, int i,int j,int m,vector<vector<int>>& dp){
    if(i<0 || j<0 || j>=m) {
        return INT_MIN;
    }

    if(i==0 ){
        return matrix[i][j];
    }

    if(dp[i][j]!=-1) return dp[i][j];

    return dp[i][j] = matrix[i][j] + 
    max(solve(matrix,i-1,j,m,dp), max(solve(matrix,i-1,j-1,m,dp),solve(matrix,i-1,j+1,m,dp)));

}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    vector<int> ans;
    for(int j=0;j<m;j++){
        ans.push_back(solve(matrix,n-1,j,m,dp));
    }

    int maxi=INT_MIN;

    for(auto i : ans){
        maxi=max(maxi,i);
    }
    return maxi;
}
