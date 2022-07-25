class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start = self.findFirst(nums, target)
        if start == -1: 
            return [-1, -1]
        
        return [start, self.findEnd(nums, target)]
    
    
    
    def findFirst(self, arr, target):
        l = 0 
        r = len(arr)-1
        while l <= r:
            m = l + (r-l)//2
            if arr[m] < target: 
                l = m+1 
            elif arr[m] > target:
                r = m-1
            elif m > 0 and arr[m] == target and arr[m-1] == target: 
                r = m-1 
            elif arr[m] == target and ((m>0 and arr[m-1] != target) or m == 0):
                return m 
        
        return -1
    
    def findEnd(self, arr, target): 
        len_arr = len(arr)
        l = 0 
        r = len_arr-1
        while l < r:
            m = l + (r-l)//2
            if arr[m] < target: 
                l = m+1 
            elif arr[m] > target:
                r = m-1
            elif m < len_arr and arr[m] == target and arr[m+1] == target: 
                l = m+1 
            elif arr[m] == target and ((m<len_arr and arr[m+1] != target) or m == len_arr-1):
                return m 
        
        if arr[r] == target: 
            return l
        return -1
