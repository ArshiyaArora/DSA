//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  private:
  int lcs(int n, string s1, string s2)
    {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if (s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
    
  public:
    int longestPalinSubseq(string A) {
        string B="";
        int n=A.length();
        for(int i=n-1;i>=0;i--){
            B+=A[i];
        }
        return lcs(n,A,B);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
