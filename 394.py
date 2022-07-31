class Solution:
    def decodeString(self, s: str) -> str:
        self.len_s = len(s)
        i = 0
        return self.recursive(s, i)
        
    def recursive(self, s, i): 
        curr_s = ""

        while i < self.len_s:
            l = s[i]
            if self.isInteger(l):
                sequence, i = self.getSequence(s, i)
                curr_s += sequence
            else: 
                curr_s += l
            i += 1
                
        return curr_s
                
    def getSequence(self, s, pos):
        repeats, start = self.getFullInteger(s, pos)
        string, end = self.getString(s, start+1, repeats)
        return (string, end)

        
    # returns the last position of the integer and the integer
    def getFullInteger(self, s, pos):
        integer = ""
        while self.isInteger(s[pos]):
            integer += s[pos]
            pos+=1
            
        return (int(integer), pos)
    
    def isInteger(self, letter):
        return ord('0') <= ord(letter) and ord('9') >= ord(letter)
                    
        
    def getString(self, s, start, repeats):
        curr_s = ""
        i = start
        while i < self.len_s:
            if s[i] == "]":
                return (repeats*curr_s, i)
            elif self.isInteger(s[i]):
                sequence, i = self.getSequence(s, i)
                curr_s += sequence
            else: 
                curr_s+= s[i]
            i+=1
                
        return ("",0)
