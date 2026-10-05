class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size()/3;
        unordered_map<int , int>mp;
        for(auto it:nums){
            mp[it]++;
            if(mp[it]>n){
                ans.push_back(it);
                mp[it]=INT_MIN;
            }
        }
        return ans;
    }
};