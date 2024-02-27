//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  private:
  const int MOD = 1e9 + 7;
    int solve(int n, int sum1, int sum2, int target, vector<vector<int>>& dp, int i, vector<int>& A, 
    int total_sum) {
        if (i >= n) {
            if ((sum1 - sum2) == target) {
                return 1;
            } else {
                return 0;
            }
        }

        if (dp[i][sum1 - sum2 + total_sum] != -1) return dp[i][sum1 - sum2 + total_sum];

        // add to sum1
        int a = solve(n, sum1 + A[i], sum2, target, dp, i + 1, A,total_sum);

        // add to sum2
        int b = solve(n, sum1, sum2 + A[i], target, dp, i + 1, A,total_sum);
        return dp[i][sum1 - sum2 + total_sum] = (a + b)%MOD;
    }

  public:
    int findTargetSumWays(int n, vector<int>& A, int target) {
        int total_sum = 0;

        for (auto i : A) {
            total_sum += abs(i);
        }
        vector<vector<int>> dp(n + 1, vector<int>(2 * total_sum + 1, -1));
        return solve(n, 0, 0, target, dp, 0, A,total_sum);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(N, arr, target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
