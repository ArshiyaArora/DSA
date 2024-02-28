//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    long long int solve(int coins[], int i, int sum, vector<vector<long long int>>& dp) {
        if (i < 0) {
            if (sum == 0) return 1;
            else return 0;
        }

        if (dp[i][sum] != -1) return dp[i][sum];

        // not take
        long long int notTake = solve(coins, i - 1, sum, dp);

        // take
        long long int take = 0;
        if (sum >= coins[i])
            take = solve(coins, i, sum - coins[i], dp);

        return dp[i][sum] = notTake + take;
    }

public:
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>> dp(N, vector<long long int>(sum + 1, -1));
        return solve(coins, N - 1, sum, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
