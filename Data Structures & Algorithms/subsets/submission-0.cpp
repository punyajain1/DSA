class Solution {
public:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& ans){
        //PUSHING EVERY SUBSET INTO FINEL SET
        ans.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums,j+1,sub,ans);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        subsets(nums, 0, sub, ans);
        return ans;
    }
};
