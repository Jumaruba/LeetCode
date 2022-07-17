class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        # time: O(t)
        # space: O(1)
        
        s_pos = 0 
        s_size = len(s)
        if s_size == 0:
            return True 

        for index, letter in enumerate(t): 
            if letter == s[s_pos]:
                s_pos += 1
                if s_pos >= s_size: 
                    return True
                
            
        return False 
