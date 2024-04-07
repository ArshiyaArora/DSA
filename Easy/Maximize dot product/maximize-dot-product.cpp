//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	    int dpmemo(int i,int j,int n, int m, int a[], int b[],vector<vector<int>> &dp,int diff){
        if(i==n || j==m)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int take= a[i]*b[j] + dpmemo(i+1,j+1,n,m,a,b,dp,diff);
        int notTake=0;
        
        if(diff)
         notTake = dpmemo(i+1,j,n,m,a,b,dp,diff-1);
        
        return dp[i][j]=max(take,notTake);
    }
    int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        vector<vector<int>> dp(n,vector<int>(m,-1));
       return dpmemo(0,0,n,m,a,b,dp,n-m);
       
       
    } 

 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends