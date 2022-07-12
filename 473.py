
# BRUTE FORCE O(n*n!) :0
class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        # mmc = 2 * 4
        # mmc = 12 * 4 = 48 
        self.sticks_size = len(matchsticks)
        
        total = sum(matchsticks)
        self.side = total//4 
        
        if self.side * 4 != total:
            return False 
        
        return self.computePermutation(matchsticks, 0)
        
    
    def computePermutation(self, sticks, pos):
        if pos == self.sticks_size:
            return self.checkPermutation(sticks)
        
        for i in range(pos, self.sticks_size): 
            aux = sticks[:]
            aux[pos] = aux[i]
            aux[i] = sticks[pos]
            result = self.computePermutation(aux, pos+1)
            if result:
                return True 
            
        return result 
    
    def checkPermutation(self, sticks):
        num_sides = 0
        curr_sum = 0
        
        for i in range(self.sticks_size):
            curr_sum += sticks[i]
            if curr_sum == self.side:
                num_sides += 1
                curr_sum = 0
        
        
        return num_sides == 4 and curr_sum == 0

# A little fast =====================================================================
# Still O(n*n!)

class Solution:
    def makesquare(self, stick: List[int]) -> bool:
        self.stickSize = len(stick)
        self.totalSum = sum(stick)
        self.sideSize = self.totalSum//4
        
        if self.sideSize * 4 != self.totalSum:
            return False 
        
        self.chosenPosition = [False for i in range(self.stickSize)]
        self.stick = stick
        
        return self.recursive(0,0)
        
        
    def recursive(self, count, curr_sum):
        # We know that the remaining elements sum up the sideSize
        if count == 3:
            return True 
        
        if curr_sum > self.sideSize:
            return False
        
        if curr_sum == self.sideSize:
            return self.recursive(count+1, 0)
            
        for i in range(self.stickSize):
            if not self.chosenPosition[i]:
                self.chosenPosition[i] = True
                if self.recursive(count, curr_sum + self.stick[i]):
                    return True 
                self.chosenPosition[i] = False
                
        return False 

# Not checking again repeated cases, by interating from the first index =====
O(2^n)

class Solution:
    def makesquare(self, stick: List[int]) -> bool:
        self.stickSize = len(stick)
        self.totalSum = sum(stick)
        self.sideSize = self.totalSum//4
        
        if self.sideSize * 4 != self.totalSum:
            return False 
        
        self.chosenPosition = [False for i in range(self.stickSize)]
        self.stick = stick
        
        return self.recursive(0,0, 0)
        
        
    def recursive(self, count, curr_sum, pos):
        # We know that the remaining elements sum up the sideSize
        if count == 3:
            return True 
        
        if curr_sum > self.sideSize:
            return False
        
        if curr_sum == self.sideSize:
            return self.recursive(count+1, 0, 0)
            
        for i in range(pos, self.stickSize):
            if not self.chosenPosition[i]:
                self.chosenPosition[i] = True
                if self.recursive(count, curr_sum + self.stick[i], i+1):
                    return True 
                self.chosenPosition[i] = False
                
        return False 

                
        
# Using Bit mask and cache optimization (PASSED)

class Solution:
    def makesquare(self, stick: List[int]) -> bool:
        N = len(stick)
        total = sum(stick)
        
        if total %4 != 0:
            return False 
        
        side = total // 4 
        
        if max(stick) > side:
            return False 
        
        has_cache = [False] * (1 << N)
        cache = [None] * (1<< N)
        
        def canMake(mask, count, curr_sum):
            if count == 3:
                return True 
            if has_cache[mask]:
                return cache[mask]
            
            if curr_sum == side:
                return canMake(mask, count+1, 0)
            if curr_sum > side:
                return False 
            has_cache[mask] = True  

            
            for i in range(N):
                if mask & (1 << i) == 0:
                    if canMake((mask | 1 << i), count, curr_sum + stick[i]):
                        cache[mask] = True 
                        return True
            
            cache[mask] = False         
            return False 
        
        return canMake(0, 0, 0)
                
