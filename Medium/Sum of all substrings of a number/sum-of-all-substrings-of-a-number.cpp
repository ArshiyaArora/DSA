//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        long long prev=0,sum=0;
        long long MOD= 1e9 + 7;
        
        for(int i=0;i<s.length();i++){
            long long newSum = ((s[i]-'0')* (i+1)  + prev*10 )%MOD;
            sum+=newSum;
            sum%=MOD;
            prev=newSum;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends