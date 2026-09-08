class Solution {
public:
    int h[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int, int>> rt;
        int t=0;//total oranges
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    t++;
                }
                if(grid[i][j]==2){
                    rt.push({i,j});
                }
            }
        }
        while(!rt.empty()){
            int s=rt.size();
            while(s--){
                //yaha aaise dekho jaise initially 2 rotten the to dono ek saath karege naa apne adjacent ko rot ek ek min m 8 rot hue
                auto [i,j]=rt.front();
                rt.pop();//poping and checking all oranges in its adjecent direction and if they are present then making them rotten and pushing them in queue such that they can turn its adj into rotten in next time
                for (int k = 0; k < 4; k++){
                    int x=i+h[k][0];
                    int y=j+h[k][1];
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y] == 1){
                        rt.push({x,y});
                        grid[x][y]=2;
                        t--;
                    }
                }
            }
            //after converting the adj of all current in rotten moving to next
            if(!rt.empty()) ans++;
        }
        return (t==0)? ans:-1;
    }
};
