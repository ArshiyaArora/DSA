//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private: 
  void component(int i,unordered_map<int,bool>& visited,unordered_map<int,list<int>>& neighbour ){
      queue<int> q;
      q.push(i);
      visited[i]=true;
       while(!q.empty()){
           int front= q.front();
           q.pop();
           for(auto k:neighbour[front]){
               if(!visited[k]){
                q.push(k);
                visited[k]=true;
               }
           }
       }
      
  }    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        unordered_map<int,list<int>> neighbour;
        for(int i = 0; i < adj.size(); i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                if(adj[i][j] == 1 && i != j) {
                    neighbour[i + 1].push_back(j + 1);
                }
            }
        }

        
        unordered_map<int,bool> visited;
        int count=0;
        
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                count++;
                component(i,visited,neighbour);
            }
        }
        return count;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends