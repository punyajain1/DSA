class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if (n==0 || s[0]=='0') return 0;
        vector<int>dp(n+1,0);
        dp[0]=1;//there can be 1 sollution when 2 degits are present
        dp[1]=1;//there can be 1 solution when there is only 1 degits
        for(int i=2;i<=n;i++){
            int a=s[i-1]-'0';//taking single previous degit 
            int b=(s[i-2]-'0')*10 + (s[i-1]-'0'); //taksing both previous degits as single degit
            if(a>=1 && a<=9) dp[i]+=dp[i-1];
            if(b>=10 && b<=26) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
