#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std; 

vector<int> nums_; 
void backtracking(vector<vector<int>>& ans, int start){
	for (int i = start; i < nums_.size() ; i++) {
		if (i == start || (nums_[i] != nums_[start] && nums_[i] != nums_[i-1]) ){
			swap(nums_[i], nums_[start]); 
			if (i != start) ans.push_back(nums_); 
			backtracking(ans, start+1); 
			swap(nums_[i], nums_[start]); 
		} 
	} 
} 
vector<vector<int>> permuteUnique(vector<int>& nums ) {
	sort(nums.begin(), nums.end()) ; 
	nums_ = nums; 
	vector<vector<int>> ans; 
	backtracking(ans, 0); 
	ans.push_back(nums); 

	return ans; 

}

int main(){

	vector<int> nums = {1,2,2,3,3}; 
	vector<vector<int>> ans = permuteUnique(nums); 
	for (auto i: ans){ for (int j: i ) cout << j << " "; cout << endl; } 
	
} 
