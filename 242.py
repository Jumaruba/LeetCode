
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
