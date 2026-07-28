class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int temp=1;
            int x=0;
            while(x<i){
                temp*=nums[x];
                x++;
            }
            x=i+1;
            while(x<n){
                temp*=nums[x];
                x++;
            }
            ans[i]=temp;
        }
        return ans;
    }
};
