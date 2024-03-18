//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    long long solve(vector<long long>&prices, int n,vector<vector<long long>>& dp,int i,int buy,int fee){
        if(i==n) return 0;
        
        if(dp[i][buy]!= -1) return dp[i][buy];
        
        long long profit = 0; 
        //buy
        if(buy){
            profit = max((-prices[i] + solve(prices,n,dp,i+1,0,fee)),solve(prices,n, dp,i+1,1,fee));
        }
        
        //sell 
        else profit = max((prices[i] + solve(prices,n,dp,i+1,1,fee)-fee), solve(prices,n,dp,i+1,0,fee));
        
        return dp[i][buy]= profit;
    }
    
    public:
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        vector<vector<long long>> dp(n+1,vector<long long>(2,-1));
        return solve(prices,n,dp,0,1,fee);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends