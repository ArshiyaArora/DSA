int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}

	vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
	for(int i=0;i<n;i++){
		dp[i][0]=true;
	}
	dp[0][arr[0]] =true;

	for(int i=1;i<n;i++){
		for(int target=1;target<=sum;target++){
			bool notTake=dp[i-1][target];
			bool take= false;
			if(target>=arr[i]){
				take= dp[i-1][target-arr[i]];
			}
			dp[i][target]=take | notTake;
		}
	}

	int mini = INT_MAX;
	for (int i = 0; i <= sum / 2; i++) {
	    if (dp[n - 1][i] == true) {
	        int diff = abs((sum - i) - i);
	        mini = min(mini, diff);
	    }
	}
	return mini;
}
