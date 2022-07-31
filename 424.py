class Solution:
    # k = 0 
    # k = 1 
    # was 
    # [(1, w), (2,a), (3,s)]
    
    def characterReplacement(self, s: str, k: int) -> int:
        h = collections.defaultdict(int)
        start = 0
        maxCount = 0
        for index, letter in enumerate(s): 
            h[letter] += 1
            maxCount = max(maxCount, h[letter])
            
            if index-start+1-maxCount > k:
                h[s[start]]-=1
                start+=1
                
        return index-start +1
