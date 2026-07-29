class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r=numbers.size()-1,l=0;
        while(l<r){
            int a=numbers[l]+numbers[r];
            if(a==target){
                return{l+1,r+1};
            }
            if(a<target) l++;
            else r--;
        }
        return {};
    }
};
