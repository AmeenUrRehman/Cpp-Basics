#include <bits/stdc++.h> 

int solveMem(vector<int> &num, int tar,vector<int> &dp){
    // Base Case
    if(tar < 0){
        return 0;
    }

    if(tar == 0){
        return 1;
    }

    if(dp[tar] != -1){
        return dp[tar];
    }

    int ans = 0;
    for(int i = 0 ; i < num.size() ; i++){
        ans += solveMem(num , tar - num[i] , dp);
    }

    dp[tar] = ans;
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
   vector<int> dp(tar+1,-1);
   return solveMem(num,tar,dp);
}