//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
    long long reversedBits(long long x) {
        // Convert decimal integer to binary representation
        bitset<32> bits(x);
        string binaryString = bits.to_string();

        // Reverse the binary string
        reverse(binaryString.begin(), binaryString.end());

        // Convert the reversed binary string back to decimal integer
        bitset<32> reversedBits(binaryString);
        return reversedBits.to_ulong();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends