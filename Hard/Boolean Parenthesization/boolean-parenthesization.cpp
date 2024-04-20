//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    const int MOD = 1003;
public:
    int countWays(int n, string s) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                for (int isTrue = 0; isTrue <= 1; isTrue++) {
                    if (i > j) continue;
                    if (i == j) {
                        dp[i][j][isTrue] = (isTrue ? s[i] == 'T' : s[i] == 'F');
                        continue;
                    }
                    int ways = 0;
                    for (int ind = i + 1; ind <= j - 1; ind += 2) {
                        int tr = dp[ind + 1][j][1] % MOD;
                        int tl = dp[i][ind - 1][1] % MOD;
                        int fr = dp[ind + 1][j][0] % MOD;
                        int fl = dp[i][ind - 1][0] % MOD;
                        if (s[ind] == '|') {
                            if (isTrue) {
                                ways = (ways + (tr * tl) % MOD + (tr * fl) % MOD + (fr * tl) % MOD) % MOD;
                            } else {
                                ways = (ways + (fl * fr) % MOD) % MOD;
                            }
                        } else if (s[ind] == '&') {
                            if (isTrue) {
                                ways = (ways + (tr * tl) % MOD) % MOD;
                            } else {
                                ways = (ways + (fl * fr) % MOD + (tr * fl) % MOD + (fr * tl) % MOD) % MOD;
                            }
                        } else if (s[ind] == '^') {
                            if (isTrue) {
                                ways = (ways + (tr * fl) % MOD + (fr * tl) % MOD) % MOD;
                            } else {
                                ways = (ways + (fl * fr) % MOD + (tr * tl) % MOD) % MOD;
                            }
                        }
                    }
                    dp[i][j][isTrue] = ways;
                }
            }
        }

        return dp[0][n - 1][1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends