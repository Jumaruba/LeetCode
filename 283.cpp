class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0); 
    }
};

/**class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return; 
        int zeros = 0; 
        for (auto it = nums.begin(); it != nums.end(); it++){
            if (*it == 0){
                nums.erase(it); 
                it--; 
                zeros++; 
            }
        }
        for (int i = 0; i < zeros; i++){
            nums.push_back(0); 
        }
    }
};**/
