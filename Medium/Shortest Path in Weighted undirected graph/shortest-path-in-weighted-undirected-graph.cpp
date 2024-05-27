//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<pair<int,int>> dist(n+1,{INT_MAX,-1});
        queue<int>q;
        q.push(1);
        dist[1] = {0,-1};
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            for(auto it:adj[front]){
                int node = it.first;
                int dis = it.second;
                if(dis+dist[front].first < dist[node].first){
                    dist[node] = {dis + dist[front].first, front};
                    q.push(node);
                }
            }
        }
        
        if (dist[n].first == INT_MAX) {
            return {-1};
        }
        
        int ind = n;
        vector<int> ans;
        
        while(ind!=-1){
            ans.push_back(ind);
            ind = dist[ind].second;
        }
        
        ans.push_back(dist[n].first);
        reverse(ans.begin(),ans.end());
        // for(int it:ans){
        //     cout<<it<<" ";
        // }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends