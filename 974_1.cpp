#include<iostream>
#include<vector>
#include <unordered_map> 

using namespace std;

#define FOR(i, x) for(i = 0; i < int(x); i++ )
#define FIR(i, x) for(i = 1; i < int(x); i++ )
/*
    prefix sum  (TIMEOUT) O(n^2) 
    ========== 
    sum = 5 
    4 5 0 -2 -3 1 5 
    4 9 9  7  4 5 10  => prefix sum 

    prefix sun with hashmap! 

*/

class Solution {
public:
    int subarraysDivByK(vector<int>& n, int k) {
        int nSize = n.size(); 

        unordered_map<int, int> um; 
        um[0] = 1; 
        
        int ps[nSize + 1]; 
        memset(ps, 0, sizeof(ps)); 
        ps[0] = 0; 

        int i, total = 0, tmp = 0; 

        FIR(i, nSize+1){
            tmp = (ps[i-1] + n[i-1]) % k; 
            ps[i] = tmp < 0? k + tmp: tmp; 
            if (um.find(ps[i]) != um.end()) total += um[ps[i]];
            um[ps[i]] ++; 
        } 
       
        return total; 
    }
};