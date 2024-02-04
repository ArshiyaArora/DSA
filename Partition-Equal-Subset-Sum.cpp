class Solution {
private:
    bool solve(vector<int>& arr,int i,int target, vector<vector<int>>& dp){
        if(target ==0) return true;
        
        if(i==0) return arr[i]==target;
        
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
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i:nums){
            sum+=i;        
        }

        if(sum%2!=0) return false;
        else{
            int target=sum/2;
            vector<vector<int>>dp(n,vector<int>(target+1,-1));
            return solve(nums,n-1,target,dp);
        }
    }
};
