class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; i++){
            for(int j = 0; j<cols; j++){
                if(i==0 && j==0)    continue;
                if(!j)  grid[i][j] += grid[i-1][j];
                else if(!i)  grid[i][j] += grid[i][j-1];
                else{
                   grid[i][j] += min(grid[i][j-1], grid[i-1][j]); 
                }
            }
        }
        return grid[rows-1][cols-1];
    }
};
