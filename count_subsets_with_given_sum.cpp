int mod = 1e9 + 7;
int perfectSum(int arr[], int n, int sum)
{
      // Your code goes here
      int dp[n+1][sum+1];
      sort(arr, arr+n);
      reverse(arr, arr+n);
      for(int i=0; i<=n; i++){        //i = no of elements left
          for(int j=0; j<=sum; j++){    //j = capacity left in bag
              if(i==0){dp[i][j]=0;}
              if(j==0){dp[i][j]=1;}
          }
      }


      for(int i=1; i<=n; i++){
          for(int j=1; j<=sum; j++){
              if(arr[i-1]>j){
                  dp[i][j] = dp[i-1][j]%mod;
              }else{
                  dp[i][j] = (dp[i-1][j] + dp[i-1][j-arr[i-1]])%mod;
              }
          }
      }
      return dp[n][sum];
}

};
/*  //recursive solution=>
  int mod = 1e9 + 7;
int rec(int sum, int n, int *arr, vector<vector<int>> &dp){
     if(n == 0 && sum != 0){
         return 0;
     }
     if(sum == 0 && n == 0){
         return 1;}

    if(arr[n-1]>sum){
        return (rec(sum, n-1, arr, dp))%mod;
    }else{
        return (rec(sum, n-1, arr, dp) + rec(sum-arr[n-1], n-1, arr, dp))%mod;
    }

}
int perfectSum(int arr[], int n, int sum)
{
      // Your code goes here
      vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
      return rec(sum, n, arr, dp);
}
*/

/*  //memoization code=>
  int mod = 1e9 + 7;
int rec(int sum, int n, int *arr, vector<vector<int>> &dp){
    if(sum == 0){return 1;}
    if(n == 0){return 0;}

    if(dp[n][sum]!=-1){return dp[n][sum]%mod;}

    if(arr[n-1]>sum){
        dp[n][sum] = (rec(sum, n-1, arr, dp))%mod;
    }else{
        dp[n][sum] = (rec(sum, n-1, arr, dp) + rec(sum-arr[n-1], n-1, arr, dp))%mod;
    }
    return dp[n][sum];
}
int perfectSum(int arr[], int n, int sum)
{
      // Your code goes here
      sort(arr, arr+n);
      reverse(arr, arr+n);
      vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
      return rec(sum, n, arr, dp);
}
