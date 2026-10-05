class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c=0,l=0,r=nums.size()-1;
        while(c<=r){
            if(nums[c]==0){
                swap(nums[c],nums[l]);
                l++;
                c++;
            }else if(nums[c]==1){
                c++;
            }else if(nums[c]==2){
                swap(nums[c],nums[r]);
                r--;
            }
        }

    }
};