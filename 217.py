
# O(nlogn)
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        l = sorted(nums)
        for i in range(1,len(l)): 
            if l[i] == l[i-1]:
                return True
            
        return False 
      
# O(n)

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        h = set()
        for i in nums: 
            if i in h:
                return True
            else:
                h.add(i)
                
        return False
      
