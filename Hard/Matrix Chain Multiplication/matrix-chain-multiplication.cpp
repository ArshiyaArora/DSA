//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{

private:
    int solve(int i,int j,int arr[],vector<vector<int>>& dp){
        if(i==j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini= 1e9;
        for(int k=i;k<j;k++){
            int ans=arr[i-1]*arr[k]*arr[j] +solve(i,k,arr,dp) + solve(k+1,j,arr,dp);
            mini=min(mini,ans);
        }
        return dp[i][j]= mini; 
    }

public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int>(N,-1));
        if(N==1) return 0;
        int i=1;
        int j =N-1;
        return solve(i,j,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends