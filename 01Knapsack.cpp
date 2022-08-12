/*------------------Tabulation------------------------*/
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   int dp[n+1][W+1];
   for(int i=0; i<=n; i++){
       for(int j=0; j<=W; j++){
           if(i==0 || j==0){dp[i][j]=0;continue;}
           else if(wt[i-1]>j){
               dp[i][j]=dp[i-1][j];
           }else{
               dp[i][j]=max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
           }
       }
   }
   return dp[n][W];
}

/* //DP memoization
int ks(int cap, int wt[], int val[], int n, vector<vector<int>> &dp){
    if(n==0 || cap==0){return 0;}

    if(dp[n][cap]!=-1){return dp[n][cap];}  //lookup

    if(wt[n-1]>cap){        //weight of element more than capacity of bag
        dp[n][cap] = ks(cap, wt, val, n-1, dp); //excluded  //updating
    }
    else{
        dp[n][cap] = max(ks(cap, wt, val, n-1, dp),
        val[n-1] + ks(cap-wt[n-1], wt, val, n-1, dp));  //updating
    }
    return dp[n][cap];
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   vector<vector<int>> dp(n+1, vector<int> (W+1, -1));
   return ks(W, wt, val, n, dp);
}*/


/*  //Recursion solution
int ks(int cap, int wt[], int val[], int n){
    if(n==0 || cap==0){return 0;}
    int profit;
    if(wt[n-1]>cap){        //weight of element more than capacity of bag
        profit = ks(cap, wt, val, n-1); //excluded
    }
    else{
        profit = max(ks(cap, wt, val, n-1), val[n-1] + ks(cap-wt[n-1], wt, val, n-1));
    }
    return profit;
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   return ks(W, wt, val, n);
}
*/
