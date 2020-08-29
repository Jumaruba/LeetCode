class Solution {
public:
vector<int> nums_; 
void backtracking(vector<vector<int>>& ans, vector<int>& temp, int start){
	
	ans.push_back(temp); 
	
	for (int i = start; i < nums_.size(); i++){
		
		temp.push_back(nums_[i]); 
		backtracking(ans, temp, i+1); 
		temp.pop_back(); 
	} 
	
	
} 
vector<vector<int>> subsets(vector<int>& nums) {
	nums_ = nums;  
	vector<vector<int>> ans;   
	vector<int> temp;
	backtracking(ans,temp, 0);  
	return ans; 
}

  
};
