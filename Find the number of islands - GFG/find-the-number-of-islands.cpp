//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private: 
    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>> &visited,int n,int m){
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;

            // Check adjacent cells
            if (col - 1 >= 0 && grid[row][col - 1] == '1' && !visited[row][col - 1]) {
                q.push({row, col - 1});
                visited[row][col - 1] = true;
            }
            if (row + 1 < n && grid[row + 1][col] == '1' && !visited[row + 1][col]) {
                q.push({row + 1, col});
                visited[row + 1][col] = true;
            }
            if (col + 1 < m && grid[row][col + 1] == '1' && !visited[row][col + 1]) {
                q.push({row, col + 1});
                visited[row][col + 1] = true;
            }
            if (row - 1 >= 0 && grid[row - 1][col] == '1' && !visited[row - 1][col]) {
                q.push({row - 1, col});
                visited[row - 1][col] = true;
            }
            if (row - 1 >= 0 && col - 1 >= 0 && grid[row - 1][col-1] == '1' && !visited[row - 1][col-1]) {
                q.push({row - 1, col-1});
                visited[row - 1][col-1] = true;
            }
            if (row + 1 < n && col+1<m && grid[row + 1][col+1] == '1' && !visited[row +1][col+1]) {
                q.push({row +1, col+1});
                visited[row + 1][col+1] = true;
            }
            if (row + 1 < n && col-1>=0 && grid[row + 1][col-1] == '1' && !visited[row +1][col-1]) {
                q.push({row +1, col-1});
                visited[row + 1][col-1] = true;
            }
            if (row - 1 >=0  && col+1<m && grid[row - 1][col+1] == '1' && !visited[row-1][col+1]) {
                q.push({row -1, col+1});
                visited[row - 1][col+1] = true;
            }
        }
    }

  
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    bfs(grid,i,j,visited,n,m);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends