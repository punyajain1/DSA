class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=0;
        for(auto it:nums){
            n=n^it;
        }
        return n;
    }
};