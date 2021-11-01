class Solution:
    def solve(self, b: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # Check which cells should not be flipped.
        self.b = b
        
        self.m = len(b)
        self.n = len(b[0])
        
        # first line
        for i in range(self.n):
            if self.b[0][i] == 'O': 
                self.dfs(0, i)
        
        # last line
        for i in range(self.n):
            if self.b[self.m - 1][i] == 'O': 
                self.dfs(self.m - 1, i)
                
        # first col
        for i in range(self.m):
            if self.b[i][0] == 'O':
                self.dfs(i, 0) 
                
        # last col              
        for i in range(self.m):
            if self.b[i][self.n - 1] == 'O':
                self.dfs(i, self.n - 1)
        
        for i in range(self.m):
            for j in range(self.n):
                if self.b[i][j] == 'o':
                    self.b[i][j] = 'O'
                elif self.b[i][j] == 'O':
                    self.b[i][j] = 'X'
                    
        return self.b
        
    def dfs(self, i, j):
        if self.b[i][j] == 'o': return 
        self.b[i][j] = 'o'
        if (i > 0 and self.b[i-1][j] == 'O'): self.dfs(i-1, j)
        if (j > 0 and self.b[i][j-1] == 'O'): self.dfs(i, j-1)
        if (j < self.n-1 and self.b[i][j+1] == 'O'): self.dfs(i, j+1)
        if (i < self.m-1 and self.b[i+1][j] == 'O'): self.dfs(i+1, j)
        
