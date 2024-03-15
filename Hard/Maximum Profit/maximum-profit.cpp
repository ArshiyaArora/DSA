//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    int solve(int target, int N, int A[],int i,vector<vector<int>>& dp,int K){
        if(i==N || target==2*K){
            return 0;
        }
        
        if(dp[i][target]!=-1) return dp[i][target];
        
        if(target%2 == 0){
            //buy the stock at ith price
            int bought = solve(target+1,N,A,i+1,dp,K) - A[i];
            
            //look for lower price to buy
            int notBought = solve(target,N,A,i+1,dp,K);
            
            return dp[i][target] = max(bought,notBought);
        }
        else{
            
            //sell at ith price
            int sold = solve(target+1,N,A,i+1,dp,K) + A[i];
            
            //look for higher price to sell
            int notSold = solve(target,N,A,i+1,dp,K);
            
            return dp[i][target] = max(sold,notSold);
        } 
        
    }
  public:
    int maxProfit(int K, int N, int A[]) {
        vector<vector<int>> dp(N,vector<int>(2*K,-1));
        
        return solve(0,N,A,0,dp,K);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends