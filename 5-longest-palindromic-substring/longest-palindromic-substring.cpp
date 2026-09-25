class Solution {
public:
    string longestPalindrome(string s) {
        int ri=0, l=0;
        int n=s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                //dp[i+1][j-1] represent the sub set of s[i...j] which is s[i+1.....j-1] is a palindrom
                if (s[i] == s[j] && (j-i <=2 || dp[i+1][j-1])){
                    dp[i][j] = true;// means s[i...j] is palindrom
                    if (l < (j-i+1)) {
                        ri = i;
                        l = j-i+1;
                    }
                }
            }
        }

        return s.substr(ri, l);
    }
};