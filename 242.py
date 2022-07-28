
#O(n logn)
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
        
#O(n)
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_size = len(s)
        t_size = len(t)
        
        if s_size != t_size:
            return False 
    
        s_hash = self.getStringHash(s)
        for index, letter in enumerate(t):
            if s_hash.get(letter, 0) == 0:
                return False 
            s_hash[letter] -= 1 
            
        return True 
    
    def getStringHash(self, s):
        _hash = {}
        for index, letter in enumerate(s): 
            value = _hash.get(letter, 0) 
            _hash[letter] = value + 1
        return _hash
    
# O(n) : using default ict
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        h = collections.defaultdict(int)
        for i,l in enumerate(s):
            h[l] += 1
            
        for i,l in enumerate(t):
            h[l] -= 1
            if h[l] < 0:
                return False
        return True
        
        
        
