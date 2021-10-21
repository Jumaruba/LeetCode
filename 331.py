class Solution:
    def isValidSerialization(self, p: str) -> bool:
        expected = 1
        p = p.split(",")
        for l in p: 
            if l == '#': 
                expected -= 1
            else: 
                if expected == 0: return False
                expected += 1
            
            if expected < 0: 
                return False 
            
            
        return expected == 0
            
