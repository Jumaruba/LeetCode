#include <iostream> 
#include <vector>

using namespace std; 

 //this solutions is correct but has time limit exceeded D: 
int findMaxLength1(vector<int>& nums) {
	if (nums.size() == 0) return 0; 
	int bestStart = 0; 
	int bestEnd = 0;  
	bool validate = false; 
	for (int i = 0 ; i < nums.size() ; i++){ 
		int zeros = 0; 
		int ones = 0; 
		int actualEnd = i; 
		int j = i; 
 		for (j = i ; j < nums.size(); j++) { 
			if (nums[j] == 0) zeros ++; 
			if (nums[j] == 1) ones ++;  
			if (zeros == ones) actualEnd = j; 
		} 
		if (actualEnd- i +1 > bestEnd - bestStart +1 ) {
			validate = true; 
			bestStart = i; 
			bestEnd = actualEnd; 
	 }  
} 	
	if (!validate) return 0;
	return bestEnd - bestStart +1; 
} 

//finally accepted 
int findMaxLength(vector<int>& nums) { 
	int count = 0;   
	int maxSize = 0; 
    size_t m = nums.size(); 
	vector <long int> countarr(2*m+1,-m-1) ; 
	for (unsigned long int i = 0; i < nums.size() ; i++) 	{	
   		count += nums[i] == 1? 1: -1;  
	 	if (countarr[count +m] == -m-1) countarr[count+m] = i; 
		else if ( i - countarr[count + m] > maxSize) maxSize = i - countarr[count + m] ; 
		if (count == 0) maxSize = i + 1 > maxSize ? i+1: maxSize;   

	} 

	return maxSize; 
}

int main(){
	vector<int> t1 = {0,1}; 
	vector<int> t2 = {0,1,0};  
	vector<int> t3 = {1,1,1,1,1,1}; 
	vector<int> t4 = {0,0,1}; 
	cout << findMaxLength(t1) << endl; 
	cout << findMaxLength(t2) << endl; 
	cout << findMaxLength(t3) << endl;  
	cout << findMaxLength(t4) << endl; 

} 
