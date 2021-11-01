import queue
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = queue.Queue()
        m = len(grid)
        n = len(grid[0]) 
        notRotting = 0

        # Find routing and adds to the queue
        for i, line in enumerate(grid):
            for j, orange in enumerate(line): 
                if orange == 2: q.put([i,j])
                elif orange == 1: notRotting += 1
        
        # No rotting orange. 
        if q.empty() and notRotting != 0:
            return -1
        # We don't have oranges.
        elif notRotting == 0:
            return 0
        

        def getAdjacentRotting(i: int, j: int):
            if i > 0 and grid[i-1][j] == 1: yield [i-1,j]
            if j > 0 and grid[i][j-1] == 1: yield [i,j-1]
            if i < m-1 and grid[i+1][j] == 1: yield [i+1,j]
            if j < n-1 and grid[i][j+1] == 1: yield [i,j+1] 

        days = 0
        while not q.empty():
            temp = []   
            while not q.empty():
                orange = q.get()
                for newRotting in getAdjacentRotting(orange[0], orange[1]): 
                    temp.append(newRotting)
                    grid[newRotting[0]][newRotting[1]] = 2
                    notRotting-= 1
                    
            for newRotting in temp:
                q.put(newRotting)
            
            days += 1
        
        # Orange cannot be reached. 
        if notRotting > 0: 
            return -1
        
        # Have answer.
        return days -1 







