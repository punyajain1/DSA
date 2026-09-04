class Solution {
public:
    void solve(vector<vector<int>> &res,vector<int> &ans,vector<int>& candidates, int target,int i, int n){
        if(target==0){
            res.push_back(ans);
            return;
        }
        for(int j=i;j<n;j++){
            if(candidates[j]>target) break;
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            ans.push_back(candidates[j]);
            solve(res,ans,candidates,target-candidates[j], j+1, n);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n=candidates.size();
        vector<vector<int>> res;
        vector<int>ans;
        solve(res,ans, candidates,target,0,n);
        return res;
    }
};
