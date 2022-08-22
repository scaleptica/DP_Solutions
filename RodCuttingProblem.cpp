// DP table=>



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
