class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid.empty() == true) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(m , vector<int>(n , 0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    ans = max(ans , bfs( i , j , vis , grid));
                }
                
            }
        }

        return ans;
    }

    int bfs(int row , int col ,vector<vector<int>> &vis, vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int , int>> q;
        vis[row][col] = 1;
        q.push({row , col});

        int delrow[] = {-1 , 0 , 1 ,  0};
        int delcol[] = {0 , -1 , 0 , 1};
        int cnt = 1;
        while(!q.empty()){
            int newr = q.front().first;
            int newc = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; i ++){
                int nr = newr + delrow[i];
                int nc = newc + delcol[i];

                if(nr < m && nr >= 0 && nc < n && nc >= 0 && vis[nr][nc] == 0 && grid[nr][nc] == 1){
                    vis[nr][nc] = 1;
                    cnt++;
                    q.push({nr , nc});
                }    
            }
        }

        return cnt;
        
    }
};
