# O(n) time complexity
class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        len_s = len(s)
        len_t = len(t)
        
        if abs(len_s - len_t) > 1 or t == s: 
            return False 
        inc_s, inc_t = self.getIncreases(len_s, len_t)

        pos_s = 0
        pos_t = 0
        is_diff = False 
        while pos_t < len_t and pos_s < len_s: 
            if t[pos_t] == s[pos_s]: 
                pos_t += 1
                pos_s += 1 
            elif not is_diff: 
                is_diff = True 
                pos_t += inc_t
                pos_s += inc_s 
            else: 
                return False 
        return True 
                
        
        
    def getIncreases(self, len_s, len_t):
        # Insert
        if len_s - len_t == 1: 
            return (1,0)
        # Delete    
        elif len_s - len_t == -1:
            return (0,1)
        # Replace
        else:
            return (1,1)
