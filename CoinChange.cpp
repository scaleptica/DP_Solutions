// dp table code=>
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
    
        for(int j = 0; j<=amount; j++){
            dp[0][j] = 1e9;
        }
        for(int i = 0; i<=n; i++){
            dp[i][0] = 0;
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=amount; j++){
                if(coins[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                }
            }
        }
        
        if(dp[n][amount] == 1e9)
            return -1;
        else 
            return dp[n][amount];
    }
};

/*  //memoization solution=>
class Solution {
public:
    int rec(vector<int>& coins, int amount, int i, vector<vector<int>> &dp){
        if(amount == 0){return 0;}
        if(coins.empty() && amount>0){return INT_MAX-1;}
        if(i>coins.size()-1 || amount<0){return INT_MAX-1;}

        if(dp[i][amount]!=-1){return dp[i][amount];}
        
        if(amount>=coins[i]){
            dp[i][amount] = min(1+rec(coins, amount-coins[i], i, dp), rec(coins, amount, i+1, dp));
        }else{
            dp[i][amount] = rec(coins, amount, i+1, dp);
        }
        return dp[i][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        int ans = rec(coins, amount, 0, dp);
        if(ans == INT_MAX-1)
            return -1;
        else 
            return ans;
    }
};*/

/*  //recursive solution=>
class Solution {
public:
    int rec(vector<int>& coins, int amount, int i){
        if(amount == 0){return 0;}
        if(coins.empty() && amount>0){return INT_MAX-1;}
        if(i>coins.size()-1 || amount<0){return INT_MAX-1;}

        
        if(amount>=coins[i]){
            return min(1+rec(coins, amount-coins[i], i), rec(coins, amount, i+1));
        }else{
            return rec(coins, amount, i+1);
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = rec(coins, amount, 0);
        if(ans == INT_MAX-1)
            return -1;
        else 
            return ans;
    }
};*/
