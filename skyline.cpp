#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 


int main(){
    vector<vector<int>> grid{{3, 0, 8, 4}, 
                             {2, 4, 5, 7},
                             {9, 2, 6, 3},
                             {0, 3, 1, 0} }; 

    int size = grid.size(); 
    //getting the max for each line
    vector<int> max_line;
    for (int i = 0; i < size; i++)
        auto max = max_element(grid[i].begin(), grid[i].end()); 
        cout << max << endl; 
        //max_line.push_back(max); 
    
    //changing all the elements
    /**
    for (int i = 0; i < size; i++){
        grid[0] = vector<int>(size, max_line[i]); 
    }
    for (vector<int> v1: grid){
        cout << endl; 
        for (int v2: v1)
            cout << v2  << " "; 
    }
    return 0; 
    **/
}