int binarySearch(vector<int> v, int target){
	if (v.size() == 0)
		return -1; 

	int low = 0, high = v.size()-1, mid; 
	while (low+1 < high){
		mid = low + (high-low)/2; 

		if(v[mid] == target) return mid; 
		else if(v[mid] > target) low = mid; 
		else high = mid; 

	}

	//case low+1 == high
	if(v[low] == target) return low; 
	else if(v[high] == target) return high; 
	return -1; 
}