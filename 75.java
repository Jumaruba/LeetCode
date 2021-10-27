class Solution {
    public void sortColors(int[] nums) {
        int size = nums.length; 
        int mid = 0, left = 0, right = size -1;  
        while(mid <= right){
            if (mid < size && nums[mid] == 2) {
                nums[mid] = nums[right]; 
                nums[right--] = 2;                
            }
            if (mid < size && nums[mid] == 0){
                nums[mid] = nums[left];  
                nums[left++] = 0;
                mid = left > mid? left: mid; 
            } 
            if (mid < size && nums[mid] ==  1){
                mid++; 
            }
            
        }
    }

}
