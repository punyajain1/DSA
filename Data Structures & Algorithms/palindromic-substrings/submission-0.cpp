class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length() , cnt=0;
        // vector<vector<int>> dp(n,vector<int>(n,0));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=i;j<n;j++){
        //         //bottom up approach , if ends are same and internal sub string is already a palindrome or length is <=2 then it is palindrome
        //         if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])){
        //             dp[i][j]=1;
        //             cnt++;
        //         }
        //     }
        // }


         for(int i=0;i<n;i++){
            int x=i,y=i;
            while(x>=0 && y<n && s[x]==s[y]){
                x--,y++,cnt++;
            }
            x=i,y=i+1;
            while(x>=0 && y<n && s[x]==s[y]){
                x--,y++,cnt++;
            }

        }
        return cnt;
    }
};