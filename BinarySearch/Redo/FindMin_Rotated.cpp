class Solution {
public:
    int findMin(vector<int>& nums) {
    int size = nums.size();

    if (!size) return -1;
    if (size == 1) return nums[0];

    int low = 0, high = size-1, mid;

    while (low <= high){
        mid = low + (high -low)/2;

        if ((high-low) == 1){
            if (nums[low] > nums[high]) return nums[high];
            else return nums[low];
        }
        
        if (nums[low] <= nums[high]) return nums[low];
        if (nums[low] < nums[mid]) low = mid+1;
        else if (nums[low] > nums[mid]) high = mid;

        
    }
        return -1; 

}
};