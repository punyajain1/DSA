class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [](pair<int,int>& a, pair<int,int>& b){return a.second < b.second;});
        int n=vec.size();
        vector<int> ans;
        for(int i=n-1;i>=n-k;i--){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
