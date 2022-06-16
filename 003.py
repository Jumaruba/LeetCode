class Solution:
    
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0 
        
        self.storage = {}
        c1 = 0

        maxStringSize = 0 
        
        for c2, letter in enumerate(s):
            self.addToStorage(letter) 
            maxStringSize = max(maxStringSize, c2 - c1)     

            while c1 < c2 and  self.isRepeated(letter): 
                self.removeFromStorage(s[c1])
                c1 += 1 

        maxStringSize = max(maxStringSize, c2- c1 + 1)
        return maxStringSize 
    
    
    def addToStorage(self, letter): 
        if letter not in self.storage.keys():
            self.storage[letter] = 1
        else:
            self.storage[letter] += 1
    
    def removeFromStorage(self, letter):
        if letter in self.storage.keys():
            self.storage[letter] -= 1
    
    
    # Return if the letter is repeated inside the storage.
    def isRepeated(self, letter): 
        if letter in self.storage.keys():
            return self.storage[letter] > 1 
        
        return False 
    
