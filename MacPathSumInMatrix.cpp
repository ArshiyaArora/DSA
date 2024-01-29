#include <bits/stdc++.h> 

using namespace std;

int solve(vector<vector<int>> &matrix, int i, int j, int m,vector<vector<int>>& dp){
    if(i<0 || j<0 || j>=m){
        return INT_MIN;
    }

    if(i==0){
        return matrix[0][j];
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int maxi = INT_MIN;  
    maxi = max(solve(matrix, i-1, j, m,dp), solve(matrix, i-1, j-1, m,dp));
    maxi = max(maxi, solve(matrix, i-1, j+1, m,dp));
    return dp[i][j]= maxi + matrix[i][j];
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    vector<int> arr;

    for(int j = 0; j < m; j++){
        arr.push_back(solve(matrix, n-1, j, m,dp));
    }

    int maxi = INT_MIN;  
    for(auto i: arr){
        maxi = max(maxi, i);
    }
    return maxi;
}
