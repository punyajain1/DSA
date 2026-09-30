class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1;
        vector<vector<int>>dp(m, vector<int>(n,0));// contains number of times can a i,j place reach
        
        dp[0][0]=1;// start position
        for(int i=1;i<m;i++){
            dp[i][0]=1; // column 1 as it can only move down not up so this wont be reached again after one case
        }
        for(int i=1;i<n;i++){
            dp[0][i]=1;// row 1 as it can only move right so they cant be reached again after one case 
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]; // we can move to a plce from above and left so adding number of times can be reached above adn number of times can be reached from left 
            }
        }
        return dp[m-1][n-1];
    }
};
