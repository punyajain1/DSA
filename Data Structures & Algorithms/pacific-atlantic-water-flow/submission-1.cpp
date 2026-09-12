class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& h,vector<vector<bool>>& vis,int r, int c) {
        vis[r][c] = true;
        int dir[5] = {0,1,0,-1,0};
        for(int k=0;k<4;k++){
            int nr = r + dir[k];
            int nc = c + dir[k+1];

            if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if(vis[nr][nc])
                continue;

            if(h[nr][nc] < h[r][c])
                continue;

            dfs(h, vis, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));

        // Pacific
        for(int i=0;i<m;i++)
            dfs(heights, pac, i, 0);

        for(int j=0;j<n;j++)
            dfs(heights, pac, 0, j);

        // Atlantic
        for(int i=0;i<m;i++)
            dfs(heights, atl, i, n-1);

        for(int j=0;j<n;j++)
            dfs(heights, atl, m-1, j);

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};