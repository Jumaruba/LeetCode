
# O(W1 + W2) 

# The main solution here was to merge all the words2 in one single hash

class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        result = []
        self.h2 = self.compileWords(words2)
        
        for w1 in words1: 
            h1 = self.hashWord(w1)
            if self.isUniversal(h1):
                result.append(w1)
            
        return result 
        
    def isUniversal(self, h1):
        for l,n in self.h2.items():
            if h1[l] == '' or self.h2[l] > h1[l]:
                return False
        return True 
    
    def compileWords(self, words):
        h = collections.defaultdict(int)
        for w in words:
            h_curr = collections.defaultdict(int)
            for l in w:
                h_curr[l] += 1
                h[l] = max(h[l], h_curr[l])
                
        return h
    
    def hashWord(self, word):
        h = collections.defaultdict(int)
        for i in word:
            h[i]+=1
        return h
