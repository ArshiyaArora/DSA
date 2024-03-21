//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &arr) {
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);

        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[prev]< arr[i] && dp1[prev]+1 > dp1[i]){
                    dp1[i] = dp1[prev]+1;
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>i;prev--){
                if(arr[prev]<arr[i] && dp2[prev]+1 >dp2[i]){
                    dp2[i] = dp2[prev] +1;
                }
            }
        }

        vector<int> ans(n);
        int maxi=0;
        
        for(int i=0;i<n;i++){
            ans[i] = dp1[i] + dp2[i] - 1;
            if(dp1[i]!=1 && dp2[i]!=1 && ans[i]>maxi)
                maxi=ans[i];
        }
        return maxi;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> nums(n);
        Array::input(nums,n);
        
        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends