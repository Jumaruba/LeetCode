#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std; 
vector<int> nums_; 

void backtracking(vector<vector<int>> & ans, vector<int>& temp, int start){
	
	ans.push_back(temp);
	
	for (int i = start; i< nums_.size() ; i++){
		if (i == start || nums_[i] != nums_[i-1]){
			temp.push_back(nums_[i]);  
			
			backtracking(ans, temp, i+1) ; 
			temp.pop_back(); 
		} 
	}
} 
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    if (nums.size() == 0) return {{}};  
    sort(nums.begin(), nums.end()); 
    nums_ = nums; 
    vector<vector<int>> ans; 
    vector<int> temp; 
    backtracking(ans, temp, 0); 
    return ans;    
}

int main(){
	
	vector<vector<int>> ans;  
	vector<int> nums = {1,2,2} ; 
	ans = subsetsWithDup(nums); 
	for (auto i: ans){
		 for (int j: i) cout << j << " " ; 
		 cout << endl; 
	 } 
} 
