/*Solution works on interviewbit*/
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
    
    int mini = INT_MAX;
    int s1 = 0, s2 = 0;
    for(int i=0; i<=sum; i++){
        if(dp[n][i]==true){
            s1 = i;
            s2 = sum - s1;
            mini = min(mini, abs(s1-s2));
        }
    }
    return mini;
}
