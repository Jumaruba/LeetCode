int binarySearch(vector<int> v, int target){
	if (v.size() == 0)
		return -1; 
	int low = 0, high = v.size(), mid;
	while(low < high){
		mid = low + (high-left)/2; 

		if (v[mid] == target) return mid; 
		else if(v[mid] < target) low = mid+1; 
		else if(v[mid] > target) high = mid; 
	} 

	if (low!=nums.size() && v[low]==target) return low; 
	return -1; 
}