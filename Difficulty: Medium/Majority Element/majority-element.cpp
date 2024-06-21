//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        double half= double(size)/2;
        // cout<<half;
        sort(a,a+size);
        int cnt;
        int i=0;
        int element;
        while(i<size){
            cnt=1;
            element =a[i];
            while(a[i+1] == element && i<size){
                cnt++;
                i++;
            }
            if(cnt>half) return element;
            else i++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends