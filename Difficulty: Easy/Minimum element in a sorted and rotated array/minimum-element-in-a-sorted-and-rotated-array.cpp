//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n) {
        int l = 0;
        int h = n - 1;
        
        while (l < h) {
            int mid = l + (h - l) / 2;
            
            // Directly return mid if it's the minimum
            if (arr[mid] < arr[mid - 1]) {
                return arr[mid];
            }
            
            // Determine which part to search
            if (arr[mid] > arr[h]) {
                // Minimum must be in the right part
                l = mid + 1;
            } else {
                // Minimum must be in the left part
                h = mid;
            }
        }
        
        return arr[l];  // The left pointer will point to the minimum element
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends