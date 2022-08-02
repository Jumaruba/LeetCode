class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        self.toSum = [] 
        result = "0"
        s_n1 = len(num1)
        self.s_n2 = len(num2)
        for i in range(s_n1-1, -1, -1):
            n1 = num1[i]
            zeroes = s_n1 - 1 - i
            self.toSum.append(self.multiply_(n1, num2, zeroes))
        
        for i,n in enumerate(self.toSum):
            result = self.sum(result, n)
        
        if result[0] == '0':
            return '0'
        
        return result
    
    def multiply_(self,n1,n2, zeros): 
        ans = ""
        carry = 0
        n1 = self.getNumber(n1)
        for i in range(self.s_n2-1, -1, -1): 
            n = n2[i]
            aux = n1 * self.getNumber(n) + carry 
            carry = aux // 10 
            aux %= 10
            ans = self.getStr(aux) + ans 
        
        if carry != 0:
            ans = self.getStr(carry) + ans
        
        for i in range(zeros): 
            ans = ans + "0"
        return ans
            
            
        
    def sum(self, n1, n2): 
        
        p1 = len(n1) - 1 
        p2 = len(n2) - 1 
        carry = 0
        result = ""
        position = 0
        while p1 >= 0 and p2 >= 0: 
            int1 = self.getNumber(n1[p1])
            int2 = self.getNumber(n2[p2])
            s = int1 + int2 + carry
            result = str(s%10) + result
            carry  = s // 10 
            p1 -= 1
            p2 -= 1
            
        while p1 >= 0: 
            int1 = self.getNumber(n1[p1])
            s = int1 + carry 
            result = str(s%10) + result
            carry = s // 10 
            p1 -= 1 
            
        while p2 >= 0: 
            int1 = self.getNumber(n2[p2])
            s = int1 + carry 
            result = str(s%10) + result
            carry = s // 10 
            p2-=1
            
        if carry != 0:
            result = self.getStr(carry) + result
            
        return result 
        
        
    def getNumber(self, k):
        return ord(k) - ord('0')
    
    def getStr(self, n): 
        return chr(n + ord('0'))
        
        
