class Solution {
public:
 int dfs(vector<vector<int>>& grid,int r,int c,int count){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==0) 
            return 1;
        if(grid[r][c]==-1) 
            return 0;
        grid[r][c] = -1;
        count = dfs(grid, r + 1, c, count);
        count += dfs(grid, r - 1, c, count);
        count += dfs(grid, r, c + 1, count);
        count += dfs(grid, r, c - 1, count);
        return count;
    }
      int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if(grid[i][j] ==1) 
                    return dfs(grid,i,j,count);
            }
        }
        return 0;
    }
};