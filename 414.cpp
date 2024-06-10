#include <iostream>
#include <vector>
#include <numeric> 

using namespace std;

/*
using knapsack algorithm:
https://brilliant.org/wiki/backpack-problem/

2 subsets where the sum are equal. 
- 1 5 11 5

the sum should be: 1+5+11+5 = 22/2 = 11 

matrix. cols = items; row = sum; 
  0 1 2 3 4 5 6 7 8 9 10 11
0 0 0 0 0 0 0 0 0 0 0 0  0
1 0 1 1 1 1 1 1 1 1 1 1  1
2 0 1 1 1 1 5 6 6 6 6 6  6 
3 0 1 1 1 1 5 6 6 6 6 10 11 
4 

3 3 3 4 5 => 3 + 3 + 3 + 4 + 5 = 18/2= 9


*/
class Solution {
public:
    bool canPartition(vector<int>& n) {
        int sum = reduce(n.begin(), n.end());
        int nSize = n.size();
        int t= sum/2; 
        if (t*2 != sum) return false; 

        int m[nSize+1][t+1]; 
        int tmp; 
        memset(m, 0, sizeof(m));

        for (int i = 0 ; i < t; i++) 
            m[0][i] = 0;

        for (int i = 1; i < nSize+1; i++) {
            for (int j = 1 ; j < t+1; j++) {
                if (n[i-1] > j)
                    m[i][j] = m[i-1][j]; 
                else {
                    m[i][j] = max(m[i-1][j], m[i-1][j-n[i-1]] + n[i-1]); 
                }

                if (m[i][j] == t) {
                    return true;
                }
            }
        }

        return false; 
    }

};