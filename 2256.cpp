#define ll long long 

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        size_t n = nums.size(); 
        long long res = 0, avg_r = 0, avg_l = 0, s_r = 0, s_l = 0, t = 0; 
        
        for (long long num: nums) {
            s_r += num;
        }
        t = s_r; 

        for (size_t i = 0; i < n; i++) {
            s_l += nums[i]; 
            s_r -= nums[i]; 
            avg_r = s_l/(i+1); 
            avg_l = n-i-1 != 0? s_r/(n-i-1): 0; 
            if (abs(avg_r - avg_l) < t) {
                t = abs(avg_r - avg_l);
                res = i; 
            }
        }
        cout << res << endl;
        return res; 
    }
}
