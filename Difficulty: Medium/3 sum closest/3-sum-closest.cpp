//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        int minDiff = INT_MAX;
        int expectedSum =0;
        sort(A,A+N);
        
        for(int i=0;i<N;i++){
            int pointer1 = i+1;
            int pointer2 = N-1;
            while(pointer1 < pointer2){
                int sum = A[pointer1] + A[pointer2] + A[i];
                int diff = abs(X-sum);
                if(diff < minDiff){
                    minDiff = diff;
                    expectedSum = sum;
                }
                if(sum>X) pointer2--;
                else if(sum==X) return sum;
                else if(sum<X) pointer1++;
            }
        }
        return expectedSum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends