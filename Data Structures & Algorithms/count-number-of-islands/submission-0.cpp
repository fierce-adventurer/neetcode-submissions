class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    cnt++;
                    bfs(i , j , vis , grid);
                }
            }
        }

        return cnt;
    }

    void bfs(int row , int col , vector<vector<int>> &vis, vector<vector<char>>& grid){
        queue<pair<int , int>> q;
        vis[row][col] = 1;
        q.push({row , col});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
           
            int nr = q.front().first;
            int nc = q.front().second;
            q.pop();
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int nrow = nr + delRow[i];
                int ncol = nc + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&        vis[nrow][ncol] == 0 && grid[nrow][ncol] == '1'){
                        vis[nrow][ncol] = 1;
                        q.push({nrow , ncol});
                }


            }
        }
    }
};
