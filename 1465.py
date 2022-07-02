class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        # O(nlogn)
        horizontalCuts = sorted(horizontalCuts)
        verticalCuts = sorted(verticalCuts)
        MODULE = pow(10,9) + 7
        maxHorGap = self.getMaxGap(horizontalCuts, h)
        maxVerGap = self.getMaxGap(verticalCuts, w)
        
        modMaxHorGap = maxHorGap % MODULE
        modMaxVerGap = maxVerGap % MODULE 
        
        return (modMaxHorGap * modMaxVerGap) % MODULE 
    
    
    
    def getMaxGap(self, arr: List[int], size: int):
        maxElement = 0
        prevElement = 0
        for index, numb in enumerate(arr):
            maxElement = max(maxElement, numb - prevElement)
            prevElement = numb
        
        maxElement = max(maxElement, size - arr[-1])
        return maxElement 
            
