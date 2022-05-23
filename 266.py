# Time complexity O(n)
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        a = [0 for i in range(26)]
        for letter in s: 
            a[self.getPos(letter)] += 1
            
        hasOdd = False 
        for i in a:
            if i % 2 != 0:
                if not hasOdd:
                    hasOdd = True 
                else:
                    return False 
        return True 
            
    def getPos(self, letter):
        return ord(letter)- ord('a')
