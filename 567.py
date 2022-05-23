#O(n) time complexity
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if (len(s1) > len(s2)):
            return False
        a1 = [0 for i in range(26)]
        a2 = [0 for i in range(26)]
        for index, letter in enumerate(s1): 
            a1[self.getPos(letter)] += 1
            
        s2_len = len(s2)
        r = len(s1) -1
        l = 0 
        for i in range(l, r+1): 
            a2[self.getPos(s2[i])] += 1
            
        while(r < s2_len-1):
            if a2 != a1:
                r+= 1
                a2[self.getPos(s2[r])] += 1
                a2[self.getPos(s2[l])] -= 1
                l+= 1
            else: 
                return True 
            
        return a2 == a1       
    def getPos(self, letter):
        return ord(letter)- ord('a')
