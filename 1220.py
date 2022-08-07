class Solution:
    def countVowelPermutation(self, n: int) -> int:
        module = 1_000_000_000 + 7
        currDict = {'a': 1, 'e': 1, 'i': 1, 'o': 1, 'u': 1}
        canHaveOnLeft = {'a': ['u','i','e'], 'e': ['a', 'i'], 'i': ['e', 'o'], 'o': ['i'], 'u': ['o','i']}
        nextDict = collections.defaultdict(int)
        vowels =  ['a', 'e', 'i', 'o', 'u']
        
        for i in range(2, n+1): 
            for l in vowels:
                for onLeftLetter in canHaveOnLeft[l]:
                    nextDict[onLeftLetter] = (nextDict[onLeftLetter] + currDict[l]) % module
                    
            currDict = nextDict
            nextDict = collections.defaultdict(int)
            
        res = 0
        for key,val in currDict.items():
            res = (res + val) % module
        
        return res
            
        
                    
                
        
        
