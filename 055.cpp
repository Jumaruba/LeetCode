class Solution {
public:
    bool canJump(vector<int>& nums) {
        
    int size = nums.size(); 
	int c[size]; 
	memset(c,0 , sizeof(c)); 
	for (int i = size - 1; i >= 0 ; i--) { 
		int actual = nums[i]; //actual jump 
		if (nums[i]+ i >= size-1) c[i] =  true; 
		else {
            if ( c[i + actual] == 1) c[i] = true; 
            else{
		 	while (c[i + actual] == 0 && actual > 0) {
				actual --; 
				if (c[i + actual] == 1 ) {
					c[i] = true; 
					break; 
				}
			} 
            }	
		} 	
	

	} 
	return c[0];
    }
};
