class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        vector<int> lps(n, 0);
        int len = 0;
        for (int i = 1; i < n; i++) {
            // If characters match, increment length and store in lps
            if (s[i]==s[len]) {
                len++;
                lps[i]=len;
            }
            // If mismatch occurs and len is not zero, fallback using lps
            else if(len!=0){
                len=lps[len-1];
                i--;
            }
        }
        return s.substr(0,lps[n-1]);
    }
};