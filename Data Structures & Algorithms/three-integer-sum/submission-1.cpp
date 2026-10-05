class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i=0;i<nums.size();i++) {
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1, r=nums.size()-1;
            while(l<r){
                //If the sum is smaller than 0, a larger value is required, so left moves forward. If the sum is greater than 0, a smaller value is required, so right moves backward.
                int sum=nums[i]+nums[l]+nums[r];
                if(sum>0) {
                    r--;
                }else if(sum<0){
                    l++;
                }else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l<r && nums[l]==nums[l-1]){
                        l++;
                        //Since equal values are adjacent after sorting duplicate values at fixed, left can be skipped directly instead of using an additional set.
                    }
                }
            }
        }
        return res;
    }
};
