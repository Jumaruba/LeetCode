class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        def check2(nums, arr, pos): 
            if nums[pos-1] == nums[pos]:
                if pos >= 2:
                    return arr[i-2]
                else:
                    return 1 

        def check3(nums, arr, pos):
            if (nums[pos-1] == nums[pos] == nums[pos-2]) or (nums[pos] == nums[pos-1] + 1 == nums[pos-2] + 2):
                if pos >= 3: 
                    return arr[i-3]
                else: 
                    return 1 
        s_nums = len(nums)
        arr = [0 for i in range(s_nums)] 

        for i in range(1, s_nums): 
            if check2(nums, arr,i) or check3(nums, arr,i):
                arr[i] = 1   

        return arr[s_nums-1]
    
