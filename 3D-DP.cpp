//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int maxPath(int i, int j1, int j2, vector<vector<int>>& grid, int n,int m,
    vector<vector<vector<int>>> &dp) {
        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) {
            return INT_MIN;
        }
    
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
    
        if(dp[i][j1][j2] !=-1 ) return dp[i][j1][j2];
    
        int maxi = INT_MIN;
    
        for (int col1 = -1; col1 <=1; col1++) {
            for (int col2 = -1; col2 <=1; col2++) {
                int value=0;
                if(j1==j2) value = grid[i][j1];
                else value= grid[i][j1] + grid[i][j2];
                value+=maxPath(i + 1, j1 + col1, j2 + col2, grid, n, m,dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2]=maxi;
}

  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return maxPath(0,0,m-1,grid,n,m,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
