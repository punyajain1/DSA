class Solution {
public:
    int maxArea(vector<int>& heights) {
        int r=heights.size()-1 , l=0;
        int ans=INT_MIN;
        while(l<r){
            ans=max(ans,(r-l)*min(heights[r],heights[l]));
            heights[l]<heights[r]? l++:r--;
        }
        return ans;
    }
};
