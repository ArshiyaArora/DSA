//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int majorityElement(int a[], int size)
    {
        
        double half= double(size)/2;
        int maj_index = 0, count = 1;
        for (int i = 1; i < size; i++) {
            if (a[maj_index] == a[i]){
                count++;
            }
            else
                count--;
            if (count == 0) {
                maj_index = i;
                count = 1;
            }
        }
        int cnt=0;
        int element = a[maj_index];
        for(int i=0;i<size;i++){
            if(a[i] == element) cnt++;
        }
        if(cnt>half) return element;
        else return -1;
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