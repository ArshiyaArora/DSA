//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  private:
    void dfs(int i,int j, vector<vector<int>>& grid,vector<vector<int>>& visited,int n, int m, vector<pair<int,int>>& vec,int r, int c){
        visited[i][j]=1;
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        vec.push_back({i-r,j-c});
        for(int k=0;k<4;k++){
            int row = i + dr[k];
            int col = j + dc[k];
            if(row>=0 && col>=0 && row<n && col<m && !visited[row][col] && grid[row][col]==1){
                dfs(row,col,grid,visited,n,m,vec,r,c);
            }
        }
    }

  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,visited,n,m,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends