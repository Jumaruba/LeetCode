class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s = self.filterString(s)
        t = self.filterString(t)
        return s == t 
            
    def filterString(self, s): 
        s_ = ""
        for i,l in enumerate(s): 
            if l == "#":
                s_ = s_[:-1]
            else: 
                s_ += l
                
        return s_ 
            
