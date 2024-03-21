//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool compareByLength(const string& a, const string& b) {
        return a.length() < b.length();
    }
    
    int longestChain(int n, vector<string>& words) {
        int maxLength = 0;
        sort(words.begin(), words.end(), compareByLength);
        vector<int> dp(n, 1);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        
        return maxLength;
    }
    
    bool isPredecessor(const string& word1, const string& word2) {
        int m = word1.length();
        int n = word2.length();
        if (n - m != 1) return false; // Predecessor must have exactly one more character
        
        int i = 0, j = 0;
        bool foundDifference = false;
        while (i < m && j < n) {
            if (word1[i] != word2[j]) {
                if (foundDifference) return false; // Already found a difference
                foundDifference = true;
                ++j; // Skip the extra character in word2
            } else {
                ++i;
                ++j;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends