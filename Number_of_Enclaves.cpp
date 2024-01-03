//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1)){
                    q.push({i,j});
                    visited[i][j]=1;
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            count--;
            for(int k=0;k<4;k++){
                int row=r+drow[k];
                int col=c+dcol[k];
                
                if(row>=0 && row<n && col>=0 && col<m && visited[row][col]==0 && grid[row][col]==1){
                    q.push({row,col});
                    visited[row][col]=1;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
