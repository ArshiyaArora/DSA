//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n= grid.size();
        int m = grid[0].size();
        if(grid[source.first][source.second]==0 || grid[destination.first][destination.second]==0) return -1;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>> q;
        
        q.push({0,{source.first,source.second}});
        dist[source.first][source.second] = 0;
        
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int dis = front.first;
            int i = front.second.first;
            int j = front.second.second;
            for(int k =0;k<4;k++){
                int row = i +dr[k];
                int col = j+dc[k];
                if(row>=0 && col>=0 && row<n && col<m && grid[row][col]==1){
                    // Check if the new distance is less than the current distance
                    if (dis + 1 < dist[row][col]) {
                        // Update the distance array with the new distance
                        dist[row][col] = dis + 1;
                        // Push the updated distance along with the cell coordinates to the queue
                        q.push({dist[row][col], {row, col}});

                    }

                }
                
            }
        }
        if(dist[destination.first][destination.second]==1e9) return -1;
        else return dist[destination.first][destination.second];
    
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends