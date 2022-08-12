int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
         int mod = pow(10,9) + 7;
    int sum=accumulate(arr.begin(),arr.end(),0);
    int sum1=(sum+d)/2;
    int dp[n+1][sum1+1];
    if((sum+d)%2 ||d>sum || sum==0)return 0;
    for(int i=0;i<=sum1;i++)dp[0][i]=0;
    for(int i=0;i<=n;i++)dp[i][0]=1;
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum1;j++){
            if(arr[i-1]<=j)dp[i][j]=(dp[i-1][j-arr[i-1]]+dp[i-1][j])%mod;
            else
                dp[i][j]=dp[i-1][j];
        }
    }
  return dp[n][sum1]; 
}
/*  //alternate sol=>
int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n==1) return A[n-1];
    int sum = 0;
    for(int i=0; i<n; i++){sum = sum + A[i];}
    
    bool dp[n+1][sum+1];
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            if(i==0){dp[i][j] = false; continue;}
            if(j==0){dp[i][j] = true; continue;}
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
                //sum value is 0
            if(A[n-1]>sum){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-A[i-1]]);
            }     
        }
    }
    
    int s1 = 0, s2 = 0, c=0;
    for(int i=0; i<=sum; i++){
        if(dp[n][i]==true){
            s1 = i;
            s2 = sum - s1;
            if(s1-s2==diff){c++};
        }
    }
    return c;
}*/
