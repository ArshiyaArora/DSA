//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  bool dfs(vector<int> adj[],int visited[],int position[],int start){
      position[start]=1;
      visited[start]=1;
      for(auto i:adj[start]){
          if(visited[i]==1 && position[i]==1){
              return true;
          }
          else if(visited[i]==0){
              bool ans=dfs(adj,visited,position,i);
              if(ans==true){
                  return true;
              }
          }
      }
      position[start]=0;
      return false;
  }
  
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int visited[V];
        int position[V];
        for(int i=0;i<V;i++){
            visited[i]=0;
            position[i]=0;
        }
        
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(dfs(adj,visited,position,i)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
