class Solution {
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int n = A.size();
        int tsum = accumulate(A.begin(), A.end(), 0);
        if((tsum+target)%2!=0){return 0;}
        int sum = (tsum + target)/2;

        int dp[n+1][sum+1];
        
        for(int j = 0; j<=sum; j++){
            dp[0][j] = 0;
        }
        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(A[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-A[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
};
/*  //recursion=>
    int rec(vector<int> &A, int n, int sum){
        if(sum==0 && n==0){return 1;}
        if(n==0){return 0;}
        
        if(A[n-1]>sum){
            return rec(A, n-1, sum);
        }else{
            return rec(A, n-1, sum-A[n-1]) + rec(A, n-1, sum);
        }
    }
    
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int n = A.size();
        int tsum = accumulate(A.begin(), A.end(), 0);
        if((tsum+target)%2!=0){return 0;}
        int sum = (tsum + target)/2;
        return rec(A, n, sum);
    }
*/

/*  //memoization=>
    int rec(vector<int> &A, int n, int sum, vector<vector<int>> &dp){
        if(sum==0 && n==0){return 1;}
        if(n==0){return 0;}
        
        if(dp[n][sum]!=-1){return dp[n][sum];}
        
        if(A[n-1]>sum){
            dp[n][sum] = rec(A, n-1, sum, dp);
        }else{
            dp[n][sum] = rec(A, n-1, sum-A[n-1], dp) + rec(A, n-1, sum, dp);
        }
        
        return dp[n][sum];
    }
    
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int n = A.size();
        int tsum = accumulate(A.begin(), A.end(), 0);
        if((tsum+target)%2!=0){return 0;}
        int sum = (tsum + target)/2;
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return rec(A, n, sum, dp);
    }
*/
