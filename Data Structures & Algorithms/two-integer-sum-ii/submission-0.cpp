class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r=numbers.size()-1,l=0;
        vector<int>ans;
        while(l<r){
            int a=numbers[l]+numbers[r];
            if(a==target){
                ans.push_back(l+1);
                ans.push_back(r+1);
            }
            if(a<target) l++;
            else r--;
        }
        return ans;
    }
};
