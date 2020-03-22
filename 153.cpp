class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0)
            return -1; 
        int low = 0, high = nums.size()-1, mid; 
        
        while(low <= high){
            mid = (high+low)/2;
            
            if(nums[high] >= nums[low]) return nums[low];
            else if(nums[mid]> nums[low]) low = mid+1; 
            else if(nums[mid] < nums[low]) high = mid; 
            if(high-low == 1){
                if(nums[low] > nums[high]) return nums[high]; 
                return nums[low]; 
             }
            
             
        }
        
    return -1; 
    }
};
