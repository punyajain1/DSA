class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));

        for (int j=0;j<=amount;j++) {
            dp[0][j]=INT_MAX - 1;
            //we dont have any coin
        }
        for(int i=1;i<=n;i++){
            //first loop start with when we have 1 coin
            // second loop start when we have atleat a amount of 1 as for amt of 0 we dont need any coin
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=min(dp[i][j-coins[i-1]]+1 , dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[n][amount]>=INT_MAX-1) return -1;
        return dp[n][amount];
    }
};
