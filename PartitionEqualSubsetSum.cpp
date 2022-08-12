class Solution {
public:
  /*-----------memoization---------------*/
    /*bool rec(int sum, int n, vector<vector<int>> &dp, vector<int>& nums){
        if(sum == 0){return true;}
        if(n == 0){return false;}
        
        if(dp[n][sum]=!-1){return dp[n][sum];}  //lookup
        
        if(nums[n-1]>sum){
            dp[n][sum] = rec(sum, n-1, dp, nums);
        }else{
            dp[n][sum] = (rec(sum , n-1, dp, nums) || rec(sum-nums[n-1], n-1, dp, nums));
        }
        return dp[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int arraySum = accumulate(nums.begin(), nums.end(), 0); //capacity
        if(arraySum%2==0){
        int sum = arraySum/2;
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return rec(sum, n, dp, nums);
        }else{return false;}
    }*/
  
  /*-------------tabulation---------------*/
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int arraySum = accumulate(nums.begin(), nums.end(), 0); //capacity
        if(arraySum%2==0){
            int sum = arraySum/2;
            bool dp[n+1][sum+1];
            
            for(int i=0; i<n+1; i++){
                for(int j=0; j<sum+1; j++){
                    if(j==0){dp[i][j]=1; continue;}
                    if(i==0){dp[i][j]=0; continue;}
                }
            }
            
            for(int i=1; i<n+1; i++){
                for(int j=1; j<sum+1; j++){
                    if(nums[i-1]>j){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i-1]]);
                    }
                }
            }
            return dp[n][sum];
        }else{
            return false;
        }
    }
};
