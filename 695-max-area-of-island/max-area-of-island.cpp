class Solution {
public:
    int h[4][4]={{1,0},{0,1},{-1,0},{0,-1}};
    int dfs(vector<vector<int>>& grid , int i, int j, int m , int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0){
            //grid is either 0 or 1 , so we dont take 0 one and do for only 1
            return 0;
        }
        //all visited becomes 0
        grid[i][j]=0;
        int res=1;
        for(int a=0;a<4;a++){
            res+=dfs(grid,i+h[a][0],j+h[a][1],m,n);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1){
                    //if we wncounder any land we do dfs on it
                    ans=max(dfs(grid,r,c,m,n),ans);
                }
            }
        }
        return ans;
    }
};