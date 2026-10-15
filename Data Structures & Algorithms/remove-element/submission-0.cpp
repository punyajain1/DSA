class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size(),t=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                //keeping trak of last index at which where value at the position is != the val
                nums[t]=nums[i];
                t++;
            }
        }
        return t;
    }
};