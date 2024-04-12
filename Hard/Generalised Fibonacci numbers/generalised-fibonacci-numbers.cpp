//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
  vector<vector<long long>>Mul(vector<vector<long long>>&mat1,vector<vector<long long>>&mat2,long long m){
     int n = mat1.size();
     vector<vector<long long>>vect(n,vector<long long>(n,0));
     for(int i = 0; i < n ; i++){
         for(int j = 0 ; j < n ; j++){
             for(int k = 0 ; k < n; k++){
                 vect[i][j] += (mat1[i][k]%m * mat2[k][j]%m)%m;
             }
         }
     }
     return vect;
  }
  
  //binary exponentiation
  vector<vector<long long>>Binexp(vector<vector<long long>> &mat,long long p,long long m){
      if(p == 1)
        return mat;
       vector<vector<long long >> res = Binexp(mat,p/2,m);
        res = Mul(res,res,m);
        if((p & 1) == 1)
          res = Mul(res,mat,m);
          
          return res;
  }
    public:
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        // code here
        
        //matrix exponentiaton
        
        if(n <= 2) return 1%m;
        vector<vector<long long>>mat{{a,b,c},{1,0,0},{0,0,1}};
        vector<vector<long long>>ans = Binexp(mat,n-2,m);
        return (ans[0][0] + ans[0][1] + ans[0][2])%m;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends