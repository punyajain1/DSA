class Solution {
public:
    bool isPalindrome(string s){
        int r=s.size();
        int l=0;
        while(l<r){
            while(l<r && !isalnum(s[l])){
                l++;
            }
            while(r>l && !isalnum(s[r])){
                r--;
            }
            if(l==r) return true;
            if(tolower(s[r])!=tolower(s[l])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
