class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        vector<int> dx = {1,0,0,-1}; 
        vector<int> dy = {0,1,-1,0}; 
        
        int numIsland = 0; 
        
        for (int i = 0 ; i< grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == '1'){
                    ++numIsland; 
                
                    queue<pair<int,int>> q; 
                    grid[i][j] = '2';
                    q.push(make_pair(i, j)); 
                    while (!q.empty()){
                        pair<int,int> coord = q.front(); 
                        q.pop(); 
                        for (int m = 0; m < 4; m++){
                            int x = coord.first + dx[m]; 
                            int y = coord.second + dy[m]; 
                            if (x < grid.size() && y < grid[i].size() && x >= 0 && y>= 0 && grid[x][y] == '1'){
                                grid[x][y] = '2'; 
                                q.push(make_pair(x,y)); 
                            }
                        }
                    }
                }
            }
        }
        
        return numIsland; 
    }
};
