class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n=s.size(),l=0;
        unordered_set<char> cset;
        for(int r=0;r<n;r++){
            while(cset.count(s[r])){
                cset.erase(s[l]);
                l++;
            }
            cset.insert(s[r]);
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
