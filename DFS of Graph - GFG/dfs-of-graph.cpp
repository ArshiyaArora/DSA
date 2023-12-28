//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfs(int& i,vector<int> &ans, unordered_map<int,bool> &isVisited,vector<int>* adj){
        isVisited[i]=true;
        ans.push_back(i);
        for (int j = 0; j < adj[i].size(); j++) {
            int neighbor = adj[i][j];
            if(!isVisited[neighbor]){
                dfs(neighbor,ans,isVisited,adj);
            }
        }
        return ans;
    }
   
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        unordered_map<int,bool> isVisited(false);
        
        for(int i=0;i<V;i++){
            if(!isVisited[i]){
                dfs(i,ans,isVisited,adj);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends