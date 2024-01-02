//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	   int n=grid.size();
	    int m =grid[0].size();
	    vector<vector<int>> dist(n, vector<int>(m, 0));
	    queue<pair<pair<int,int>,int>> q;
	    vector<vector<int>> visited(n, vector<int>(m, 0));
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                visited[i][j]=1;
	            }
	        }
	    }
	    
	    int drow[]={1,0,-1,0};
	    int dcol[]={0,1,0,-1};
	    
	    while(!q.empty()){
	        int r= q.front().first.first;
	        int c= q.front().first.second;
	        int t= q.front().second;
	        dist[r][c]=t;
	        q.pop();
	        
	        for(int i=0;i<4;i++){
	            int row=r+drow[i];
	            int col=c+dcol[i];
	            
	            if(row>=0 && row<n && col>=0 && col<m && visited[row][col]==0
	            && grid[row][col]==0){
	                q.push({{row,col},t+1});
	                visited[row][col]=1;
	            }
	        }
	        
	    }
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
