class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        self.len_pattern = len(pattern)
        self.pattern = pattern
        result = []
        
        for word in words:
            self.h = collections.defaultdict(str)
            self.map = set([])      # what letters from word are already mapped. 
            if self.checkPattern(word):
                result.append(word)
                
        return result
            
    def checkPattern(self, word):
        for word_letter, pattern_letter in zip(word,self.pattern):
            if self.h[pattern_letter] == '' and word_letter not in self.map:
                self.h[pattern_letter] = word_letter
                self.map.add(word_letter)
            elif self.h[pattern_letter] == '' and word_letter in self.map:
                return False 
            elif self.h[pattern_letter] != word_letter:
                return False 
        return True 
