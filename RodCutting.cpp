//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
 
  public:
    int cutRod(int price[], int n) {
        vector<int> prev(n+1,0), curr(n+1,0);
        
        for(int target=0;target<=n;target++){
            prev[target]=price[0] * target;
        }
        
        for(int i=1;i<n;i++){
            for(int target=0;target<=n;target++){
                
                //not take
                int notTake=prev[target];
                
                //take
                int take=0;
                if(target>=i+1){
                    take = price[i] + curr[target-i-1];
                }
                curr[target]=max(notTake,take);
            }
            prev=curr;
        }
        
        return prev[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
