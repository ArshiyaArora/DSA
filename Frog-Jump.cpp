#include <bits/stdc++.h> 

int minEnergy(int n,vector<int> &heights,vector<int>& dp){

    if(n<=1){
        return 0;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int a,b=INT_MAX;
    a = minEnergy(n - 1, heights,dp) + abs(heights[n - 1] - heights[n - 2]);
    if (n > 2) {
        b = minEnergy(n - 2, heights, dp) + abs(heights[n - 1] - heights[n - 3]);
    }
    
    return dp[n]=min(a,b);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return minEnergy(n,heights,dp);
}
