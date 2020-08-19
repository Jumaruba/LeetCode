class Solution:
    def toGoatLatin(self, s: str) -> str:
        words = s.split() 
        ans = []
        for index,i in enumerate(words):
            word = i
            if (i[0].lower() not in ['a','e','i','o','u']): word = i[1:] + i[0]
            word += 'ma' +(index+1)*'a'
            ans.append(word)
        
        return ' '.join(ans)          
        
