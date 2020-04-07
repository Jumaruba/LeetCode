class Solution:
    def minSteps(self, s: str, t: str) -> int:
        result = len(s)
        dic = collections.defaultdict(int) 
        for m in s: 
            dic[m]+=1 
        for n in t: 
             if dic[n]: 
                result-=1 
                dic[n]-=1
        return result
