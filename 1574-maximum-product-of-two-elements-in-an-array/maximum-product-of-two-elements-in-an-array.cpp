class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long m1=INT_MIN;
        long m2=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>m1){
                m2=m1;
                m1=nums[i];
            }else if(nums[i]>m2){
                m2=nums[i];
            }
        }
        return int((m1-1)*(m2-1));
    }
};