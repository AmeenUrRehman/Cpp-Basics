#include<limits.h>
int solveMem(int n, int x,int y, int z, vector<int> &dp){
	//Base Case
	if(n == 0){
		return 0;
	}

	if(n < 0){
		return INT_MIN;
	}

	if (dp[n] != -1){
		return dp[n];
	}

	int a = solveMem(n-x,x,y,z,dp) + 1;
	int b = solveMem(n-y,x,y,z,dp) + 1;
	int c = solveMem(n-z,x,y,z,dp) + 1;

	dp[n] = max(a,max(b,c));
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int> dp(n+1,-1);
	int ans = solveMem(n,x,y,z,dp);
	if(ans < 0){
		return 0;
	}
	else{
		return ans;
	}
}

// Tabulation Method
#include<limits.h>
int solveTab(int n, int x,int y, int z){
	
	vector<int> dp(n+1,INT_MIN);
	dp[0] = 0;
	for(int i = 1; i<= n; i++){
          if (i - x >= 0) {
            dp[i] = max(dp[i], dp[i - x] + 1);
          }
		  if (i - y >= 0) {
            dp[i] = max(dp[i], dp[i - y] + 1);
          }
		  if (i - z >= 0) {
            dp[i] = max(dp[i], dp[i - z] + 1);
          }
    }

	if(dp[n] < 0){
		return 0;
	}
	else{
		return dp[n];
	}
}

int cutSegments(int n, int x, int y, int z) {
	return solveTab(n,x,y,z);
}