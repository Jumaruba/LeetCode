class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        waiting = collections.defaultdict(list) 
        for it in map(iter, words):
            waiting[next(it)].append(it)
            
        for c in s: 
            for it in waiting.pop(c, ()): 
                waiting[next(it,None)].append(it)
        return len(waiting[None])
