// User function Template for C++

class Solution{

public:
    int knapSack(int N, int W, int val[], int wt[]){
        
        vector<int> prev(W+1,0);
        
        for(int target=0;target<=W;target++){
            prev[target]= (target/wt[0]) * val[0];
        }
        
        for(int i=1;i<N;i++){
            for(int target=0;target<=W;target++){
                //not take
                int notTake = prev[target];
                
                //take
                int take = 0;
                if(target>=wt[i]){
                    take = val[i] + prev[target-wt[i]];
                }
                
                prev[target]= max(take,notTake);
            }
        }
        
        return prev[W];
    }
};
