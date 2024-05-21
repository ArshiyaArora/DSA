//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        vector<int> dist(N, INT_MAX);
        queue<int> q;

        // Initialize distance for the source node
        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                int nextNode = it.first;
                int weight = it.second;
                
                // Relaxation step
                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    q.push(nextNode);
                }
            }
        }

        // Convert unreachable distances from INT_MAX to -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends