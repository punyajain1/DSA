class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        if (k>n) return ans;
        int l=0,r=0;
        while(r<=n-k){
            l=r;
            int t=INT_MIN;
            while(l<r+k){
                t=max(nums[l],t);
                l++;
            }
            r++;
            ans.push_back(t);
        }
        return ans;
    }
};
