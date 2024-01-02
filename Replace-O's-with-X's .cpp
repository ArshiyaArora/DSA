//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private: 
    void dfs(vector<vector<int>>& visited, vector<vector<char>>& mat,int i,int j,int drow[],int dcol[],int n,
    int m){
        visited[i][j]=1;
        
        for(int k=0;k<4;k++){
            int row=i+drow[k];
            int col=j+dcol[k];
            if (row >= 0 && row < n && col >= 0 && col < m && mat[row][col] == 'O' && !visited[row][col]) {
                dfs(visited, mat, row, col, drow, dcol, n, m);
            }
        }
    }
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<char>> ans=mat;
        
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && visited[i][j]==0 && (i==0 || i==n-1 || j==0 || j==m-1)){
                    dfs(visited,mat,i,j,drow,dcol,n,m);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && mat[i][j]=='O'){
                    ans[i][j]='X';
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
