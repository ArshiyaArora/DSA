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
    int stockBuyAndSell(int n, vector<int> &prices) {
        vector<int> prev(2,0),curr(2,0);
        bool buy = false;
        
        for(int i=n-1;i>=0;i--){
            for(int buy =0; buy<=1;buy ++){
                if(buy){
                //buy the stock at ith price
                    int bought = prev[!buy] - prices[i];
                    
                    //look for lower price to buy
                    int notBought = prev[buy];
                    
                    curr[buy] = max(bought,notBought);
                }
                else{
                    
                    //sell at ith price
                    int sold = prev[!buy] + prices[i];
                    
                    //look for higher price to sell
                    int notSold = prev[buy];
                    
                    curr[buy] = max(sold,notSold);
                }
            }
            prev=curr;
        }
        
        return prev[true];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
