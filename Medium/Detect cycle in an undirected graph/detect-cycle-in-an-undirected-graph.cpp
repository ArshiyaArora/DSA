//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool bfs(int i,vector<int> &visited,queue<pair<int,int>>& q,vector<int> adj[]){
        visited[i] = 1; 
        q.push({i, -1});
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int first = front.first;
            int parent = front.second;
            for (auto it : adj[first]) {
                if (visited[it] == 1 && it != parent) 
                    return true;
                else if (!visited[it]) {
                    q.push({it, first});
                    visited[it] = 1; 
                }
            }
        }
        return false;
    }
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        queue<pair<int, int>> q;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,visited,q,adj)) return true;
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends