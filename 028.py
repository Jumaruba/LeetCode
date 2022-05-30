class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        needle_size = len(needle)
        haystack_size = len(haystack) 
        
        # Case the size is not compatible 
        if needle_size == 0: 
            return 0 
        if needle_size > haystack_size:
            return -1 
        
        # Brute force algorithm O(n*m)! 
        for i in range(haystack_size - needle_size + 1): 
            s = haystack[i: i+needle_size] 
            if s == needle:
                return i 
            
        return -1
