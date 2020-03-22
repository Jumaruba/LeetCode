class Solution {
public: 
	int findPivot(vector<int>&nums){
    int low = 0;
    int high = nums.size()-1, mid;


    while (true){

        if (high - low == 0)
            return high; 
        if(nums[low] < nums[high])
            return low;

        mid = (low+high)/2;

        if (nums[high] < nums[low]){
            if (high - low == 1)	//array of two elements
                return high;
            else if (nums[mid] > nums[low])
                low = mid+1;
            else if(nums[mid] < nums[low])
                high = mid;
        }


    }
}

int binarySearch(vector<int>&nums, int high, int low, int target){
    int mid;
    while (low<=high){
        mid = (low +high)/2;

        if (nums[mid] < target)
            low = mid+1;
        else if (nums[mid] > target)
            high = mid-1;
        else
            return mid;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    if (nums.size() == 0)
        return -1; 
    //case size = 1
    if (nums.size() == 1){
        if (nums[0] == target)
            return 0;
        else return -1;
    }
    int pivot = findPivot(nums);

    //right search
    int ans1 = binarySearch(nums, nums.size()-1, pivot, target);
    //left search
    int ans2 = binarySearch(nums, pivot-1, 0, target);

    if (ans1 != -1)
        return ans1;
    else if (ans2 != -1)
        return ans2;
    else return -1;


}
};
