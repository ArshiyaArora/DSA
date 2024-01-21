#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& dp, int heights[], int k) {
    if (n <= 1) {
        return dp[n] = 0;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int mini = INT_MAX;
    for (int j = 1; j <= k && n - j >= 1; j++) {
        int a = solve(n - j, dp, heights, k) + abs(heights[n-1] - heights[n-1- j]);
        mini = min(mini, a);
    }
    return dp[n] = mini;
}

int main() {
    int n, k;
    cin >> n >> k;
    int heights[n];
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    vector<int> dp(n+1, -1);  
    int result = solve(n, dp, heights, k);
    cout << "Minimum energy required: " << result << endl;
    return 0;
}
