class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        int mult_oper = 0, counter = 0, add_oper = 0 ; 
        for (int i = 0; i < nums.size() ; i++){
            while(nums[i] != 0){
                if (nums[i]%2 == 1){
                    nums[i]-= 1; 
                    add_oper ++; 
                }
                else{
                    nums[i]/=2; 
                    counter --; 
                    mult_oper = counter < 0 ? mult_oper +1: mult_oper;
                }
            }
            counter = mult_oper; 
        }
        
        return mult_oper + add_oper; 
    }
    

};
