class Solution {
public:
    int uniquePaths(int m, int n) {
        int mat[m][n]; 
        memset(mat, 0, sizeof(mat[0][0])*m*n); 
        for (int line = 0 ; line < m; line++){
            for (int col = 0 ; col < n ; col ++){
                if (col == 0 || line == 0) mat[line][col] = 1; 
                else mat[line][col] = mat[line-1][col] + mat[line][col-1]; 
            }
        }
        return mat[m-1][n-1]; 
    }
};
