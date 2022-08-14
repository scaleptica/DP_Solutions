/*MOD IS NOT REQUIRED IN LEETCODE*/
class Solution {
  public:
    int mod = 1e9 + 7;
    long long int numberOfPaths(int m, int n){
        // code here
        int dp[m+1][n+1];
        
        for(int i = 0; i<=m; i++){
            dp[i][0] = 1;
        }
        for(int j = 0; j<=n; j++){
            dp[0][j] = 1;
        }
        
        dp[0][0] = 1;
        
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(i==1 || j==1){dp[i][j] = 1; continue;}
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            }
        }
        return dp[m][n];
    }
};
/*  //memoization=>
int mod = 1e9+7;
long long int rec(int m, int n, vector<vector<long long int>> &dp){
    if(m==1 || n==1){dp[m][n] = 1;}
    if(m==0 && n==0)return 1;
    
    if(dp[m][n]!=-1){return dp[m][n];}
    
    dp[m][n] = rec(m-1, n, dp) + rec(m, n-1, dp);
    
    return dp[m][n]%mod;
}

long long int numberOfPaths(int m, int n){
    // code here
    vector<vector<long long int>> dp(m+1, vector<long long int>(n+1, -1));
    return rec(m, n, dp)%mod;
}*/
