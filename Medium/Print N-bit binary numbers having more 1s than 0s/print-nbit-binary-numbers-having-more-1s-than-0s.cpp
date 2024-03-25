//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private:
    void find(vector<string>& s, string temp, int n,int count1, int index)
    {
        if(count1<(temp.size()+1)/2)  return;
        
        if(index==n){
            s.push_back(temp);
            return;
        }
        
        find(s, temp+'1', n, count1+1, index+1);
        find(s, temp+'0', n, count1, index+1);
    }
public:	
	 vector<string> NBitBinary(int n)
    {
        // Your code goes here
        vector<string> s;
        find(s,"",n,0,0);
        
        return s;
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends