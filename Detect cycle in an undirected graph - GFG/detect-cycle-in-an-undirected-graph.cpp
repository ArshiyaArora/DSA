//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    void cycle(unordered_map<int,int>& parent, unordered_map<int,bool>& visited,bool &flag,int i,
                vector<int> * adj,queue<int> & q){
                    
        q.push(i);
        parent[i]=-1;
        visited[i]=true;
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto neighbour: adj[front]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=true;
                    parent[neighbour] = front;
                }
                else if(visited[neighbour] && neighbour != parent[front]){
                    flag=true;
                    break;
                }
            }
        
            if(flag==true){
                break;
            }
        }
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,int> parent;
        unordered_map<int,bool> visited;
        bool flag=false;
        
        for(int i=0;i<V;i++){
            queue<int> q;
            if(!visited[i]){
                cycle(parent,visited,flag,i,adj,q);
            }
            if(flag==true){
                break;
            }
        }
        
        return flag;
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