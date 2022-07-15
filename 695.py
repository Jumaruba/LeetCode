class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        visited = []
        m = len(grid)
        n = len(grid[0])
        self.currSize = 0
        self.maxSize = 0
        
        def buildVisited():
            for i in range(m):
                visited.append([])
                for j in range(n):
                    visited[i].append(0)
                    
        def visitAdjacents(line, col):   
            if line >= m or line < 0 or col < 0 or col >= n:
                return 
            if visited[line][col]:
                return 
            if not grid[line][col]:
                return 
            
            visited[line][col] = 1 
            self.currSize += 1
            self.maxSize = max(self.maxSize, self.currSize)
            visitAdjacents(line+1, col)            
            visitAdjacents(line-1, col)            
            visitAdjacents(line, col+1)            
            visitAdjacents(line, col-1)            
            
            
        def solve():
            for line in range(m):
                for col in range(n): 
                    self.currSize = 0
                    visitAdjacents(line,col)
                    
        
            
        buildVisited() 
        solve()
        return self.maxSize
        
            
