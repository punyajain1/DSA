class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        if(nums.empty()) return {{}};
        vector<int>temp (nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(temp);
        for (const auto& p : perms) {
            for (int i = 0; i <= p.size(); i++) {
                vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[0]);
                ans.push_back(p_copy);
            }
        }
        return ans;
    }
};
