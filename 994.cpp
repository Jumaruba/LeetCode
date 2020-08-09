class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> q_row, q_col; 
        vector<vector<int>> q ; 
        bool time_zero = true; 
        for (int i = 0 ; i < grid.size(); i++){
            for (int j = 0 ; j < grid[0].size(); j++){
                if (grid[i][j] == 2){
                    q_row.push(i); 
                    q_col.push(j); 
                    grid[i][j] = 3; 
     
                } 
                time_zero = grid[i][j] == 1? 0: time_zero; 
            }
        }
        
        if (time_zero) return 0; 
        
        int minutes = -1; 
        while(!q_row.empty()){
            queue<int> q_row_aux; 
            queue<int> q_col_aux; 
            while(!q_row.empty()){
                int row = q_row.front(); 
                int col = q_col.front(); 
                q_row.pop();
                q_col.pop(); 

                if (validRange(grid, row+1, col)){
                    q_row_aux.push(row+1); 
                    q_col_aux.push(col); 
                    grid[row+1][col] = 3; 
                    
                }
                if (validRange(grid, row-1, col)){
                    q_row_aux.push(row-1);
                    q_col_aux.push(col); 
                    grid[row-1][col] = 3; 
                }
                if (validRange(grid, row, col+1)){
                    q_row_aux.push(row);
                    q_col_aux.push(col+1); 
                    grid[row][col+1] = 3; 
                }
                if (validRange(grid, row, col-1)){
                    q_row_aux.push(row);
                    q_col_aux.push(col-1); 
                    grid[row][col-1] = 3; 
                }
              
                 
            }
            minutes++; 
            q_row = q_row_aux; 
            q_col = q_col_aux; 
        }
        
        for (int i = 0 ; i < grid.size(); i++){
            for (int j = 0 ; j < grid[0].size(); j++){
                if (grid[i][j] == 1) return -1; 
            }
        }
        return minutes; 
        
        
    }
    
    int validRange(vector<vector<int>>& grid, int row,int col){
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1;  
    }

    
};
