//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int i,int j,vector<vector<int>> &visited,vector<pair<int,int>>& vec,
    vector<vector<int>>& grid, int row,int col,int n,int m){
        visited[i][j]=1;
        vec.push_back({i-row,j-col});
        int drow[] ={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        for(int k=0;k<4;k++){
            int r=i+drow[k];
            int c=j+dcol[k];
            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1 && visited[r][c]==0){
                dfs(r,c,visited,vec,grid,row,col,n,m);
            }
        }
    }
  
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,visited,vec,grid,i,j,n,m);
                    s.insert(vec);
                }
            }
        }
        return s.size();
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
