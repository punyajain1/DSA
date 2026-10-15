class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return;
        k = k % n;
        queue<int> q;
        for(int i=n-k;i<n;i++){
            q.push(nums[i]);
        }
        for(int i=0;i<n-k;i++){
            q.push(nums[i]);
        }
        int i=0;
        while(!q.empty()){
            nums[i] = q.front();
            q.pop();
            i++;
        }
    }
};