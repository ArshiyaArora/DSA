//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        vector<int> visited(100000,0);
        q.push({start,0});
        visited[start] = 1;
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int node = front.first;
            int steps = front.second;
            
            if(node == end) return steps;
            for(int i=0;i<arr.size();i++){
                int val = node * arr[i];
                if(val >= 100000) val %= 100000;
                if (!visited[val]) {
                    visited[val] = 1;
                    q.push({val, steps + 1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends