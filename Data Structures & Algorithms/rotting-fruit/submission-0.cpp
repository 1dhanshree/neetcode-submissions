class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //grid dimension
        int n = grid.size();
        int m = grid[0].size();
        //total fresh oranges
        int cntFresh = 0;
        // store row, col and time
        queue <pair<pair<int, int>, int>> q;
        int vis[n][m];

        //initially store all rotten oranges and time as 0 and coutn fresh oranges
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }else{
                    vis[i][j] = 0;
                }
                //count fresh oranges
                if(grid[i][j] == 1) cntFresh++;
            }
        }

        //Directions all 4
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, -1 ,0, 1};

        //store time and rotten fresh oranges
        int ans = 0, cnt = 0;

        //bfs
        while(!q.empty()){
            //take current row col, and time
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            //track answer
            ans = max(ans, t);

            //traverse in all directions
            for(int i = 0; i<4; i++){
                //neighboring rows and cols
                int nr = r + dr[i];
                int nc = c + dc[i];
                //check 4 conditions size, validity, freshness, vis
                if(nr >= 0 && nr <n && nc >= 0 && nc <m && grid[nr][nc] == 1 && !vis[nr][nc]){
                    //push in q, mark vis and cnt++
                    q.push({{nr, nc}, t+1});
                    vis[nr][nc] = 2;
                    cnt++;
                }
            }
        }
        // return false if any fresh oranges remain unreachable
        return cntFresh != cnt ? -1 : ans;
    }
};
