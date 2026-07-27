class Solution {
public:
    int minAddToMakeValid(string s) {
        int op=0;
        int cl=0;
        for(auto it:s){
            if(it==')'){
                if(op>0) {
                    op--;
                }
                else cl++;
            }else if(it=='('){
                op++;
            }
        }
        return op+cl;
    }
};