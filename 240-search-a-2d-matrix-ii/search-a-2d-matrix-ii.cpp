class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int a=0,b=m-1;
        while(a<n && b>=0){
            int ele=matrix[a][b];
            if(ele==target) return true;
            if(ele>target){
                b--;
            }
            else{
                a++;
            }
        }
        return false;
    }
};