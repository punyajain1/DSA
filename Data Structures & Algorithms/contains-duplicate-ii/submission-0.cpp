class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>a;
        int i=0;
        for(int j=0;j<n;j++){
            if(j-i > k){
                //if window size becomes big then remove left most from the set
                a.erase(nums[i]);
                i++;
            }
            if(a.find(nums[j])!=a.end()){
                //if none found the return true
                return true;
            }
            //else add that into the set 
            a.insert(nums[j]);
        }
        return false;
    }
};