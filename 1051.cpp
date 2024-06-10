#include<iostream>
#include<vector> 

using namespace std; 

class Solution {
public:
    int heightChecker(vector<int>& h) {
        auto c = h; 
        int ans = 0; 
        sort(c.begin(), c.end());
        for (size_t i = 0; i < h.size(); i++)
            ans = c[i] != h[i] ? ans + 1: ans; 
        return ans; 

    }
};