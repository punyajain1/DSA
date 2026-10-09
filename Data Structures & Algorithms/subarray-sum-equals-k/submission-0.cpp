class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,curr=0;
        unordered_map<int ,int>mp;
        mp[0]=1;
        for(int it:nums){
            curr+=it;
            int d=curr-k;
            ans+=mp[d];
            mp[curr]++;
        }
        return ans;
    }
};