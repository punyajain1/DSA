class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
                //popping from front as they are not required as its old index ie its out of sliding window and not needed
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
                //f encounterd less then current then remove it 
            }
            dq.push_back(i);
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};