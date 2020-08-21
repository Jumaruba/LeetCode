//time limit exceeded (i wanna diiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiie)

class Solution {
public:
    const int INF = 1e9 +1; 
	int partition(vector<int> & nums, unordered_map<int, int> freq, int b, int e){
			
		int x = freq[nums[e]]; 
		int i = b-1; 
		for (int j = b ; j < e; j++){
			if (freq[nums[j]] <= x){
				i++; 
				swap(nums[j], nums[i]); 
			} 
		} 
		swap(nums[i+1], nums[e]); 
		return i+1; 
		
	} 
	void quick_sort(vector <int> & nums, unordered_map<int,int> freq, int b, int e){
		if (b  < e){
			int p = partition(nums, freq, b ,e); 
			quick_sort(nums, freq, b, p-1) ; 
			quick_sort(nums, freq, p+1, e); 
			
		} 

	} 
	vector<int> topKFrequent(vector<int>& nums, int k){
		unordered_map<int,int> freq; 		//keep track of the sequence 
		vector <int> ans; 
        freq.reserve(2*nums.size()); 
		for (int i = 0 ; i < nums.size(); i++){
			freq[nums[i]] += 1; 
		} 
		quick_sort(nums, freq, 0, nums.size() -1);
		nums.push_back(INF) ; 
		int count = 0; 
        
		for (int i = nums.size() -2; i >= 0; i--) {
			if (freq[nums[i]] > 0){
				 ans.push_back(nums[i]);
				 count ++; 
                freq[nums[i]]*=-1; 
			 } 
			 if (count == k) break; 
		}  
		return ans; 
		
	} 
};
