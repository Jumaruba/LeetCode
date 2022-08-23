class Solution:
    def firstUniqChar(self, s: str) -> int:
        times = [0 for _ in range(26)]
        pos = 0
        
        for letter in s: 
            times[ord(letter)-ord('a')] += 1
        
        for i, letter in enumerate(s):
            if times[ord(letter)-ord('a')] == 1:
                return i
                
        return -1
            
