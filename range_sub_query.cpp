class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->nums = nums; 
        if (nums.size() != 0)
            this->sum_array.push_back(nums[0]); 
        for (int i = 1; i < nums.size(); i++) 
            this->sum_array.push_back(this->sum_array[i-1] + this->nums[i]); 
    }
    
    int sumRange(int i, int j) {
        if (nums.size() == 0) return 0; 
        if (!i) return sum_array[j]; 
        return sum_array[j] - sum_array[i-1]; 
        
    }
    vector<int> sum_array; 
    vector<int> nums; 
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
