class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, mx = INT_MIN, res = 0;
        vector<int> count(26, 0);
        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;//index of char as index of a=56 if comes s[r]== a then index will be 0
            mx = max(mx, count[s[r] - 'A']);
            if((r-l+1-mx) > k){
                count[s[l]-'A']--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
