//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
class Solution{  
private:
    bool solve(vector<int>& arr,int i,int target, vector<vector<int>>& dp){
        if(target ==0) return true;
        
        if (i < 0) return false; 
        
        if(i==0 && arr[i]==target) return true;
        
        if(dp[i][target]!=-1) return dp[i][target];
        
        bool take=false;
        if(target>= arr[i]){
            take=solve(arr,i-1,target-arr[i],dp);
            if(take) return true;
        }
        
        bool notTake=solve(arr,i-1,target,dp);
        
        return dp[i][target]=take||notTake;
    }

public:
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        int n=arr.size();
        return solve(arr,n-1,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
