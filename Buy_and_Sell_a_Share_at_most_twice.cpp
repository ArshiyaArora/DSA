//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        int maxProfit(vector<int>&price){
            int n=price.size();
            vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
            
            for(int i=n-1;i>=0;i--){
                for(int buy=0;buy<=1;buy++){
                    for(int sellCount=0;sellCount<=1;sellCount++){
                        if(buy){
                            //buy the stock at ith price
                            int bought = dp[i+1][!buy][sellCount] - price[i];
                            
                            //look for lower price to buy
                            int notBought = dp[i+1][buy][sellCount];
                            
                            dp[i][buy][sellCount] = max(bought,notBought);
                        }
                        else{
                
                            //sell at ith price
                            int sold = dp[i+1][!buy][sellCount+1] + price[i];
                            
                            //look for higher price to sell
                            int notSold = dp[i+1][buy][sellCount];
                            
                            dp[i][buy][sellCount] = max(sold,notSold);
                        }
                    }
                }
            }
            
            return dp[0][1][0];
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends
