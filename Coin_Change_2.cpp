class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[n+1][amount+1];
        
        for(int j = 0; j<=amount; j++){
            dp[0][j] = 0;
        }
        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=amount; j++){
                if(coins[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
};


/*  //memoization=>
class Solution {
public:
    int rec(int amount, vector<int>& coins, int i, vector<vector<int>> &dp){
        if(amount==0){return 1;}
        if(i>coins.size()-1 || amount<0){return 0;}
        if(coins.empty() && amount>0){return 0;}

        if(dp[i][amount]!=-1){return dp[i][amount];}
        if(amount<coins[i]){
            dp[i][amount] = rec(amount, coins, i+1, dp);
        }else{
            dp[i][amount] = (rec(amount, coins, i+1, dp) + (rec(amount-coins[i], coins, i, dp)));
        }
        return dp[i][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return rec(amount, coins, 0, dp);
    }
};*/


/*  //recursion=>
class Solution {
public:
    int rec(int amount, vector<int>& coins, int i){
        if(amount==0){return 1;}
        if(i>coins.size()-1 || amount<0){return 0;}
        if(coins.empty() && amount>0){return 0;}

        if(amount<coins[i]){
            return rec(amount, coins, i+1);
        }else{
            return (rec(amount, coins, i+1) + (rec(amount-coins[i], coins, i)));
        }
    }
    
    int change(int amount, vector<int>& coins) {
        return rec(amount, coins, 0);
    }
};*/
