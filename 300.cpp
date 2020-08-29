class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size () == 0) return 0;
        vector<int> v(nums.size()+1); 
        int v_size = 1; 
        if (nums.size() == 1) return 1; 
        v[1] = nums[0]; 
        for (int i = 1; i < nums.size() ; i++){
            int copy_size = v_size; 
            while(copy_size >= 1){
                if (nums[i] > v[copy_size]){
                    v[copy_size+1] = v[copy_size+1] == 0 || v[copy_size+1] > nums[i]? nums[i]: v[copy_size+1]; 
                    v_size = copy_size +1 > v_size? copy_size+1: v_size; 
                    break; 
                }
                copy_size --; 
            }
            if (copy_size == 0) v[1] = nums[i] < v[1] ? nums[i]: v[1]; 
            
            
        }
        for (int i = 1; i < v.size() ;i++ )
            if (v[i] == 0) return i-1; 
        return nums.size(); 

    }
};


//		5 8 3 7 9 1
//v   0 0 0 0 0 0 0  => each position i, stores the biggest value of a sequence with size i 

//iter 2:  0 5 8 0 0 0 0
//iter 3:  0 3 8 0 0 0 0
//iter 4:  0 3 7 0 0 0 0
//iter 5:  0 3 7 9 0 0 0
