/*-----------Tabulation-------------*/
bool isSubsetSum(vector<int>arr, int sum){
    // code here
    int n = arr.size();
    bool dp[n+1][sum+1];
    for(int i=0; i<=n; i++){

        for(int j=0; j<=sum; j++){
            if(j==0){dp[i][j] = true; continue;}
            if(i==0){dp[i][j] = false; continue;}   //zero elements left
            dp[i][j] = -1;
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i]>sum){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
            }
        }
    }
    return dp[n][sum];
}

/*----------Memoization----------*/
/*
bool rec(int i,vector<int>& arr, int sum,vector<vector<int>>& dp){
     //false
    if(sum==0){return 1;}       //true
    if(i==arr.size()){return 0;}
    if(dp[i][sum]!=-1){return dp[i][sum];}  //lookup
    if(arr[i]>sum){       //exclude
        return dp[i][sum] = rec(i+1,arr,sum,dp);  //update
    }
    else{
        return dp[i][sum] = (rec(i+1,arr,sum,dp) || rec(i+1,arr,sum-arr[i],dp)); 
        //The above line returns the result that is true
    }
}

bool isSubsetSum(vector<int>arr, int sum)
{
   int n=arr.size();
   vector<vector<int>>dp(n,vector<int>(sum+1,-1));
   return rec(0,arr,sum,dp);
}*/
