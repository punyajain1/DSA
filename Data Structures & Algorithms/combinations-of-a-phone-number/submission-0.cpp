class Solution {
public:
vector<string> str = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> v;
    void solve(string &d,string &ans,int i){
        if(i==d.length()){
            v.push_back(ans);
            return;
        }
        int num=d[i]-'0';
        string c=str[num];
        for(int j=0;j<c.length();j++){
            ans.push_back(c[j]);
            solve(d,ans,i+1);
            ans.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return v;
        string ans="";
        solve(digits,ans,0);
        return v;
    }
};
