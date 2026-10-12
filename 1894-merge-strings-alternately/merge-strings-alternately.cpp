class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int a=word1.size();
        int b=word2.size();
        int i=0,j=0;
        string s="";
        while(i<a && j<b){
            s+=word1[i];
            s+=word2[j];
            i++;
            j++;
        }
        while(i<a){
            s+=word1[i];
            i++;
        }
        while(j<b){
            s+=word2[j];
            j++;
        }
        return s;
    }
};