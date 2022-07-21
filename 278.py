# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        l = 0
        r = n
        while l + 1 <  r: 
            m = (r-l)//2 + l 
            if isBadVersion(m): 
                r = m
            else: 
                l = m 
        
        if isBadVersion(l): 
            return l 
        return r 
