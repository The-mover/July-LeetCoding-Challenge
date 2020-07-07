class Solution {
private:
    int dx[5] = {1, -1, 0, 0};
    int dy[5] = {0, 0, 1, -1};
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if( grid[i][j] ) {
                    for(int dir=0; dir<4; dir++) {
                        int x = i + dx[dir];
                        int y = j + dy[dir];
                        //cout << x << " " << y << "\n";
                        if( x >= n || x < 0 || y >= m || y < 0 ) ans++;
                        else if( !grid[x][y] )  ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};