class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<int> q; 
        for (int i = 0 ; i < matrix.size(); i++){
            for (int j = 0 ; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0 ) {
                    q.push(i);
                    q.push(j); 
                } 
            }
        }
        
        while(!q.empty()){
            int line = q.front(); 
            q.pop(); 
            int col = q.front(); 
            q.pop() ;
            setLine(line, matrix); 
            setCol(col, matrix); 
        }
    }
    
    void setLine(int& line, vector<vector<int>>& matrix){
        for (int i = 0 ; i < matrix[0].size(); i++) matrix[line][i] = 0; 
    }
    
    void setCol(int& col, vector<vector<int>>&matrix){
        for (int i = 0 ; i <  matrix.size(); i++) matrix[i][col] = 0; 
    }
    
    
};
