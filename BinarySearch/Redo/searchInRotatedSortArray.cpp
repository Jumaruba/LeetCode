class Solution {
public:

	//[],
	//[1],
	//[2,1]
	//[5,1,3],[4,5,6,7,0,1,2]

	//[2] mid = low = high      FIRST SITUATION 
	//[0,1,2]	low < high 		SECOND SITUATION 
	//SO IT NEEDS TO BE V[LOW] <= V[HIGH]


	//[0,1]

	//find the minimum number
	int findMinimum(std::vector<int> v){
    int low = 0, high = v.size()-1, mid;

    //low == high
    //[1]
    while (low <= high){
        mid = (low+high)/2;

        if (v[low] > v[high]){
            if (v[low] < v[mid]) low = mid +1;
            else if (v[low] > v[mid]) high = mid;
            else if (v[low] == v[mid]) return high;
        }

        else if (v[low] <= v[high]) return low;
    }
    return -1;
}
    //binary search

    int binarySearch(std::vector<int> v, int target, int low, int high){
        int mid;

        while(low <= high){
            mid = (low + high)/2;

            if (v[mid] == target) return mid;
            else if (v[mid] > target) high = mid-1;
            else if (v[mid] < target) low = mid+1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int size = nums.size();
        
    //special cases------------------------------
    	if (size == 0) return -1; 
    	if (size == 1){
    		if (nums[0] != target)
    			return -1; 
    		else return 0; 
    	}
    	if (size == 2){
    		if (nums[0] == target) return 0; 
    		if (nums[1] == target) return 1; 
    		return -1; 
    	}
    //--------------------------------------------
        
        int index = findMinimum(nums);
        int ans1 = binarySearch(nums, target, 0, index-1);
        int ans2 = binarySearch(nums, target, index, nums.size()-1);

        if (ans1 == -1 && ans2 == -1) return -1;
        else if (ans1 != -1) return ans1;
        else return ans2;

    }
};