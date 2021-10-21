class Solution:
    def minimumCost(self, n: int, connections: List[List[int]]) -> int:
        self.edges = []
        self.parents = [-1]*(n+1)
        total = 0
        for c in connections: 
            self.edges.append((c[2],c[1],c[0]))
            
        self.edges.sort() 
        
        for value, p1, p2 in self.edges: 
            if self.join(p1, p2):
                total += value 
        
        if abs(min(self.parents)) != n: 
            return -1 
        return total
        
        
    def join(self, p1, p2):
        pap1 = self.getParent(p1)
        pap2 = self.getParent(p2) 

        if pap1 == pap2: 
            return False 
        
        m = min(pap1, pap2)
        h = max(pap1, pap2) 
        self.parents[m] += self.parents[h]
        self.parents[h] = m 
        
        return True 
        
    def getParent(self, p):
        v = self.parents[p]
        while v > 0: 
            p = v 
            v = self.parents[p]
            
        return p
        
