//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
private:
    long long memo[1001][1001]; // Memoization array

    // Recursive function to find the maximum amount of money the first player can win
    long long solve(int arr[], int start, int end) {
        if (start > end)
            return 0;

        if (memo[start][end] != -1)
            return memo[start][end];

        // If the first player chooses the coin at start
        long long pick_start = arr[start] + min(solve(arr, start + 2, end), solve(arr, start + 1, end - 1));

        // If the first player chooses the coin at end
        long long pick_end = arr[end] + min(solve(arr, start + 1, end - 1), solve(arr, start, end - 2));

        // Store the maximum amount for the current subproblem
        return memo[start][end] = max(pick_start, pick_end);
    }

public:
    long long maximumAmount(int n, int arr[]) {
        memset(memo, -1, sizeof(memo)); // Initialize memoization array with -1
        return solve(arr, 0, n - 1); // Start the recursion from the beginning and end of the array
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends