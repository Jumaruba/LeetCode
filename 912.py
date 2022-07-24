class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        self.mergeSort(nums)
        return nums 
    
    def mergeSort(self, nums: List[int]) ->List[int]: 
        len_nums = len(nums)
        if len_nums <= 1: 
            return nums 
        
        mid = len_nums//2 
        
        L = nums[:mid]
        R = nums[mid:]
        
        self.mergeSort(L)
        self.mergeSort(R)
        i = j = k = 0
        
        # Merging the two arrays into a temp one
        while i < len(L) and j < len(R): 
            if L[i] < R[j]:
                nums[k] = L[i]
                k+=1
                i+=1
            else:
                nums[k] = R[j]
                k+=1
                j+=1
                
                
        while i < len(L):
            nums[k] = L[i]
            k+=1
            i+=1
            
        while j < len(R):
            nums[k] = R[j]
            k+= 1
            j+= 1 
            
        
        
    
