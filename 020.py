class Solution:
    def isValid(self, s: str) -> bool:
        q = []
        
        for i in s: 
            if i == "(":
                q.append(")") 
            elif i == "[":
                q.append("]")
            elif i == "{":
                q.append("}") 
            elif q == [] or q.pop() != i:
                return False 
                
        return len(q) == 0
