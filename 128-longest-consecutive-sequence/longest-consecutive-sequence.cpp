class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int ans=1, t=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            else if(nums[i-1]+1 == nums[i]){
                t=t+1;
            }else{
                t=1;
            }
            ans=max(ans,t);
        }
        return ans;
    }
};