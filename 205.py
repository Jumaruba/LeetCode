class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        hash_ = {} 
        set_ = set([]) 
        
        s_size = len(s)
        t_size = len(t)
        if s_size != t_size: 
            return False 
        
        
        for index, s_letter in enumerate(s):
            t_letter = t[index]    
            if s_letter not in hash_.keys() and t_letter not in set_: 
                hash_[s_letter] = t_letter
                set_.add(t_letter)
            # Two keys mapping the same letter 
            elif s_letter not in hash_.keys() and t_letter in set_: 
                return False 
            # Not corresponding to the correct mapping
            elif hash_[s_letter] != t_letter:
                return False 
                
            
            
        
        return True 
