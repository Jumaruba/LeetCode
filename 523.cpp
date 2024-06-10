#include <iostream>
#include<vector> 
#include <unordered_map>
using namespace std; 


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        size_t nSize = nums.size(); 
        unordered_map<int, int> value;  // (value, position).
        value[0] = 0;
        bool hasValue; 
        if (nSize == 1) return false; 
        
        vector<int> sums(nSize + 1, 0); 
        int currSum = 0; 

        for (size_t i = 1; i < nSize+1; i++) {
            sums[i] = (sums[i-1] + nums[i-1]) % k; 
            hasValue = value.find(sums[i]) != value.end();
            if (hasValue && i - value[sums[i]] >= 2)  return true; 
            if (!hasValue) value[sums[i]] = i; 
        }
       
        return false; 
        
    }

};