//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    const int MOD = 1e9 + 7;
  public:
    vector<int> Series(int n) {
        vector<int> ans;
        int m = n-2;
        int a=0;
        int b=1;
        ans.push_back(a);
        ans.push_back(b);
        while(m>=0){
            int temp = (a+b)%MOD;
            ans.push_back(temp);
            a=b;
            b=temp;
            m--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends