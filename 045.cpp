class Solution {
public:
    int jump(vector<int>& nums) {
        
        int curPos = 0, i = 0, prePos, n = nums.size(), level = 0; 
        
        while(curPos < n-1){
            level++; 
            prePos = curPos; 
            for (; i<= prePos; i++){
                curPos = max(nums[i] + i, curPos); 
            }
        }
        return level; 
    }
};

// Another approach

class Solution {
public:
    int jump(vector<int>& nums) {
        size_t SIZE = nums.size();
        vector<int> p(SIZE, 0);
        int e = 1; 

        for (int s = 0; s < SIZE; s++){
            while (e-s <= nums[s] && e < SIZE){
                if (p[e] == 0) p[e] = p[s] + 1;
                e++;
            }
            if (e >= SIZE) break;
        }

        return p[SIZE-1];
    }
};
