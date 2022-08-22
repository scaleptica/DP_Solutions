// DP table=>
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int dp[n+1][n+1];
        
        for(int i=0; i<=n; i++){
            dp[i][0]= 0;
        }
        
        for(int j=0; j<=n; j++){
            dp[0][j]= 0;
        }
        
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i>j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j], price[i-1]+dp[i][j-i]);
                }
            }
        }
        return dp[n][n];
    }
};


/*      //memoization=>
    int length;
    vector<vector<int>> dp;
    
    int rec(int price[], int n, int i){
        if(i>length || n<=0){return 0;}
        
        if(dp[i][n]!=-1){return dp[i][n];}
        
        if(i>n){
            return dp[i][n] = 0;//rec(price, n, i+1);
        }else{
            return dp[i][n] = max(rec(price, n, i+1), price[i-1] + rec(price, n-i, i));
        }
    }
    
    int cutRod(int price[], int n) {
        //code here
        length = n;
        vector<vector<int>> dpt(n+1, vector<int>(n+1, -1));
        dp=dpt;
        return rec(price, n, 1);
    }
*/

/*      //recursive=>
    int length;
    int rec(int price[], int n, int i){
        if(i>length || n<=0){return 0;}
        
        if(i>n){
            return rec(price, n, i+1);
        }else{
            return max(rec(price, n, i+1), price[i-1] + rec(price, n-i, i));
        }
    }
    int cutRod(int price[], int n) {
        //code here
        length = n;
        return rec(price, n, 1);
    }
*/
