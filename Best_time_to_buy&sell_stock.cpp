//  DP table=>



/*
//  Memoization =>
class Solution {
public:
    vector<vector<int>>dp;
    int rec(vector<int>& prices, int state, int i){
        if(i>=prices.size()){return 0;}
        
        if(dp[i][state]!=-1){return dp[i][state];}
        
        if(state==0){
            dp[i][state] = max(rec(prices, 1, i+1)-prices[i], rec(prices, 0, i+1));
        }else if(state==1){
            dp[i][state] = max(prices[i]+rec(prices, 0, i+2), rec(prices, 1, i+1));
        }
        return dp[i][state];
    }
        
    int maxProfit(vector<int>& prices) {
        int state = 0;  //buy or nothing, 1 means sell
        int n = prices.size();
        vector<vector<int>>dt(n+1, vector<int>(2, -1));
        dp = dt;
        return rec(prices, state, 0);
    }
};


// Recursive soln=>
class Solution {
public:
    int rec(vector<int>& prices, int state, int i){
        if(i>=prices.size()){return 0;}
        
        if(state==0){
            return max(rec(prices, 1, i+1)-prices[i], rec(prices, 0, i+1));
        }else if(state==1){
            return max(prices[i]+rec(prices, 0, i+2), rec(prices, 1, i+1));
        }
        return -111111;     //This means nothing. After an "else-if" statement ends, we need to mandatorily return something.
    }
        
    int maxProfit(vector<int>& prices) {
        int state = 0;  //buy or nothing, 1 means sell
        return rec(prices, state, 0);
    }
};*/
