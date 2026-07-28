class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(auto it:strs){
            ans += to_string(it.size()) + "#" + it;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int n=s.size();
        vector<string> ans;
        string temp="";
        int i=0;
        while(i<s.size()){
            int j=i;
            while (s[j] != '#'){
                j++;
            }
            // here j is poiting to start of the word 
            int len=stoi(s.substr(i, j-i)); // we have placed length or words before the # so we get its length 
            ans.push_back(s.substr(j+1,len));
            i = j+1+len;
        }
        return ans;
    }
};
