class Solution:
    def isHappy(self, n: int) -> bool:
        currNumber = str(n)
        prevNumber = -1
        s = set([])
        while prevNumber != currNumber: 
            prevNumber = currNumber
            currNumber = 0
            for i,l in enumerate(prevNumber): 
                currNumber += int(l)*int(l)
            
            if currNumber == 1:
                return 1 
            if currNumber in s:
                return False 
            else: 
                s.add(currNumber)
            
            currNumber = str(currNumber)
            
        return False 
            
