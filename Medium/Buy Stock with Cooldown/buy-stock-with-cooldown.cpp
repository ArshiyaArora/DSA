//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
 
    
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
         vector<vector<long long>> dp(n+2,vector<long long>(2,0));
         
        for(int i=n-1; i>=0; i--){
            for(int j=0;j<=1;j++){
                long long profit = 0; 
                if(j){
                    profit = max((-prices[i] + dp[i+1][0]),dp[i+1][1]);
                }
                
                //sell 
                else profit = max((prices[i] + dp[i+2][1]), dp[i+1][0]); 
                dp[i][j] = profit;
            }
        }
         
         return dp[0][1];
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
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends