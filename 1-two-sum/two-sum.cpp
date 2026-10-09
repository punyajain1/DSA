class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<2) return{};
        unordered_map<int,int>mp;
        //map act as a hashmap that contains the value[nums[i],i] for eg1-mp={[2,0],[7,1],[11,2],[15,3]};
        for(int i=0;i<n;i++){
            int r=target-nums[i];
            if(mp.count(r)){
                return{mp[r],i};
            }
            mp[nums[i]]=i;
        }
        return{};
    }
};