class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m; 
        int s = 0, total = 0;
        m[0] += 1;
        for (int num: nums){
            s = (s + num) % k;
            s = s < 0? k + s : s; 
            m[s] += 1;
        }
        for(auto i: m) total += i.second * (i.second-1) / 2; 
        return total;
    }
};
