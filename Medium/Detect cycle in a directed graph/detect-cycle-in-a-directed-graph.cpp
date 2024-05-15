//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(vector<int> adj[],vector<int>& visited,vector<int>& pathVis, int i){
        visited[i] =1;
        pathVis[i] =1;
        for(auto it : adj[i]){
            if(pathVis[it]==1) return true;
            else if(!visited[it]) {
                if(dfs(adj,visited,pathVis,it)) return true;;
            }   
        }
        pathVis[i] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> pathVis(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,visited,pathVis,i)) return true;
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