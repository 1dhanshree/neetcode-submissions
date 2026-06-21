class Solution {
public:
    void bfs(int row, int col, int n, int m, vector<vector<int>> &vis, vector<vector<char>>& grid){
        //store the row col in queue as starting point for bfs
        queue<pair<int,int>>q;
        q.push({row, col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            //check neighbors in eight directions
            for(int i = -1 ; i<=1; i++){
                for(int j = -1; j<= 1; j++){
                    //neighboring row and cols
                    int nr = r + i;
                    int nc = c + j;
                    //skip self and diagnals
                    if((i == 0 && j == 0) || abs(i) + abs(j) != 1 ) continue;
                    //check size, validity, if it's land and if it's visited
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]){
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        //traverse initially through grid and check for land which is not visited
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    bfs(i, j, n, m, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
