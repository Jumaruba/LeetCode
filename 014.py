class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        currCommonPrefix = strs[0]
        for i,s in enumerate(strs):
            currCommonPrefix = self.getLongestPrefix(s, currCommonPrefix)
            if currCommonPrefix == "":
                return ""
        return currCommonPrefix
    
    def getLongestPrefix(self, s1, s2): 
        commonPrefix = ""
        if len(s1) < len(s2): 
            shortest = s1 
            biggest = s2
        else:
            shortest = s2 
            biggest = s1 
            
        for i,l in enumerate(shortest):
            if l == biggest[i]:
                commonPrefix += l
            else: 
                return commonPrefix 
        return commonPrefix 
            
