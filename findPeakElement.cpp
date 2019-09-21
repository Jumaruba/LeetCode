class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size(); 
        
        //special cases  
        if(size == 0) return -1; 
        if(size == 1) return 0; 
        if (size == 2){
            if (nums[0] > nums[1]) return 0;
            return 1; 
        } 
        
        //checking the extremes
        if (nums[0] > nums[1]) return 0; 
        if (nums[size-1] > nums[size-2]) return size-1; 
        
        //checking the array
        int low = 1, high = size-2, mid; 
        while(low < high){
            mid = low + (high-low)/2; 
            if(nums[mid] > nums[mid+1] && nums[mid]>nums[mid-1]) return mid; //it will never be out of the array
            if(nums[mid] < nums[mid+1]) low = mid+1; 
            else if(nums[mid] < nums[mid-1]) high = mid-1;
            
        }
        
        //check the case low == high
        if(low == high) return low; 
        return -1;
    }
        
};

