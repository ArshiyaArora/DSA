//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:

    bool isSafe(int x,int y,int n,int m){
        if(x>=0 && y>=0 && x<n && y<m) return true;
        return false;
    }

    int findShortestPath(vector<vector<int>> &mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    for(int k=0;k<4;k++){
                        int newX=i+dr[k];
                        int newY=j+dc[k];
                        if(isSafe(newX,newY,n,m)){
                            mat[newX][newY] = -1;
                        }
                    }
                }
            }
        }
        
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            if(mat[i][0]==1){
                q.push({{i,0},1});
            }
        }
        
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int x=front.first.first;
            int y=front.first.second;
            int cnt=front.second;
            
            if(y == m - 1)
            {
                return cnt;
            }
            
            vis[x][y]=1;
            for(int k=0;k<4;k++){
                int newX=x+dr[k];
                int newY=y+dc[k];
                if(isSafe(newX,newY,n,m) && vis[newX][newY]==0 && mat[newX][newY] == 1){
                    q.push({{newX,newY},cnt+1});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends