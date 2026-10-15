class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a=0;
        int b=0;
        for(int it:nums) {
            if(b==0){
                a=it;
            }
            if(it==a){
                b++;
            } else {
                b--;
            }
        }
 
        return a;
    }
};