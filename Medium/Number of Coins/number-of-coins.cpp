//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int solve(vector<int>& coins, int target, int i, vector<vector<int>>& dp) {
        // Base cases
        if(i==0){
            if(target%coins[i]==0)
                return target/coins[0];
            else return INT_MAX;
        }
        if(dp[i][target]!=-1) return dp[i][target];

        // Not take the coin at index i
        int notTake = solve(coins, target, i - 1, dp);

        // Take the coin at index i
        int take = INT_MAX;
        if (coins[i] <= target) {
            int withTake = solve(coins, target - coins[i], i, dp);
            if (withTake != INT_MAX) {
                take = withTake + 1;
            }
        }

        return dp[i][target] = min(take, notTake);
    }

	public:
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    vector<vector<int>> dp(M,vector<int>(V+1,-1));
	    int count=0;
	    int ans= solve(coins,V,M-1,dp);
	    if (ans!=INT_MAX){
	        return ans;
	    }
	    else return -1;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends