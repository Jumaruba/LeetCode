class Solution {
public:
    int binarySearch(vector<int>& arr, int& target){
	
	int begin = 0, end = arr.size() -1, mid;  
	while(begin <= end){
		
		mid = (begin + end)/2; 
		if (arr[mid] == target) return true; 
		else if (arr[mid] < target) begin = mid + 1; 
		else if (arr[mid] > target) end = mid -1; 
		
	} 
	return false; 
	
}
    bool searchMatrix(vector<vector<int>>& matrix, int& target) {
        if (matrix.size() == 0 || matrix[0].size() == 0 ) return false; 
        for (int i = 0 ; i < matrix.size() ;i++){
            if (matrix[i][matrix[i].size() -1] >= target ) return binarySearch(matrix[i], target);   
        }   
        return false; 
    }
};
