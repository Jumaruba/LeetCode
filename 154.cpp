class Solution {
public:
    int findMin(vector<int>& nums) {

        int begin = 0, end = nums.size()-1, mid = 0; 
        while(begin <= end){
           int mid = (end-begin)/2 + begin; 
            if (nums[begin] == nums[end] && nums[begin] == nums[mid]) return linear(nums, begin, end); 
            
            if (nums[mid] <= nums[(mid+1)%nums.size()] && nums[mid] < nums[mid-1 < 0? nums.size()-1: mid-1]) return nums[mid]; 
            if (nums[begin] <= nums[mid] && nums[end] >= nums[mid]) return nums[begin]; 
            if (nums[begin] <= nums[mid] && nums[end] <= nums[mid]) begin = mid+1; 
            else if (nums[begin] >= nums[mid] && nums[end]>= nums[mid]) end = mid -1 ;
        }
        return nums[mid]; 
    }
    
    int linear(vector<int> & nums,  int& begin, int& end){
        int less = nums[begin]; 
        for (int i = begin; i < end+1; i++){
            less = min(nums[i], less); 
        }
        return less; 
    }
};
