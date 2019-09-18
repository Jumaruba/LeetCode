class Solution {
public:
    int findBegin(vector<int>&nums, int target){
        int size = nums.size();
        
        if (size == 0)
            return -1; 
        else if(size == 1){
            if(nums[0] != target)
                return -1; 
            else 
                return 0; 
        }
        
        int low = 0, high = size-1, mid; 
        while(low+1<high){
            mid = low+(high-low)/2; 
            
            if(nums[mid] == target){
                if(mid == 0) return mid; 
                else if(nums[mid-1]!= target) return mid; 
                high = mid; 
            }
            else if(nums[mid] > target) high = mid; 
            else low = mid; 
        }
        
        if(nums[low] == target) return low; 
        else if(nums[high] == target) return high; 
        return -1; 
    }
    
    int findEnd(vector<int>&nums, int target){
        int size = nums.size();
        
         if (size == 0)
            return -1; 
        else if(size == 1 && nums[0] != target){
            if(nums[0] != target)
                return -1; 
            else 
                return 0; 
        }
        
        int low = 0, high = size-1, mid; 
        while(low+1<high){
            mid = low+(high-low)/2; 
            
            if(nums[mid] == target){
                if(mid == size-1) return mid; 
                else if(nums[mid+1]!= target) return mid; 
                low = mid; 
            }
            else if(nums[mid] > target) high = mid; 
            else low = mid; 
        }
        
        if(nums[high] == target) return high; 
        else if(nums[low] == target) return low; 
        return -1; 
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1}; 
        
        ans[0] = findBegin(nums, target); 
        ans[1] = findEnd(nums, target); 
        
        return ans; 
    }
};