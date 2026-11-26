class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        // Step 1: Add all rotten oranges
        // Count all fresh oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 2) {
                    q.push({i,j});
                }

                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Four directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int minutes = 0;

        // Step 2: BFS
        while(!q.empty() && fresh > 0) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                auto [r,c] = q.front();
                q.pop();

                // Check all four directions
                for(int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Check valid cell and fresh orange
                    if(nr >= 0 && nr < m &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;

                        fresh--;

                        q.push({nr,nc});
                    }
                }
            }

            minutes++;
        }

        // Step 3: Check remaining fresh oranges
        if(fresh > 0)
            return -1;

        return minutes;
    }
};