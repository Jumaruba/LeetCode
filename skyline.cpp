#include <iostream>
#include <vector>
using namespace std; 

//this is no a good solution!
//it's basically brute force

//APROACH 1: 
class Solution {
public:
    
    int find_max(vector<int> v){
        int max = 0; 
        for (int n:v)
            max = n>max? n: max; 
        return max;   
    }

    int find_max_col(vector<vector<int>> v, int col, int size){
        int max = 0; 
        for (int i= 0 ; i < size; i++)
            max = v[i][col] > max? v[i][col]: max; 
        return max; 
    }
    
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int size = grid.size(); 

        int max = 0, maxcol; 
        //getting the max for each line
        vector<int> max_line;
        vector<int> max_col; 
        for (int i = 0; i < size; i++){
            max = find_max(grid[i]);  
            max_line.push_back(max); 
            maxcol = find_max_col(grid, i, size); 
            max_col.push_back(maxcol); 
        }


        //changing all the elements for the maximum
        int soma = 0; 
        for (int line = 0; line < size; line++){
            for (int col = 0; col < size; col ++){
                if (grid[line][col] != max_line[line] && grid[line][col] != max_col[col]) 
                    soma += min(max_line[line], max_col[col]) -grid[line][col]; 
                
        } 
        }
        return soma; 
    }
};

