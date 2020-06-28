class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0; 
        int lines = obstacleGrid.size(); 
        int cols = obstacleGrid[0].size(); 
        int mat[lines][cols]; 
        memset(mat, 0, sizeof(mat[0][0])*lines*cols); 
        for (int line = 0; line < lines; line++){
            for (int col = 0; col < cols;  col ++){
                if (obstacleGrid[line][col] == 1) mat[line][col] = 0; 
                else if (line == 0 && col != 0) mat[line][col] = mat[line][col-1]; 
                else if (col == 0 && line != 0) mat[line][col] = mat[line-1][col]; 
                else if (col == 0 && line == 0) mat[0][0] = 1; 
                else mat[line][col] = mat[line-1][col] + mat[line][col-1]; 
            }
        }
        return mat[lines-1][cols-1]; 
    }
};
