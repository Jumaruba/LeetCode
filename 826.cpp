/**
difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]

sort by (profit, difficulty)
[(50,10),(40,8),(30,6),(20,4),(10,2)]
[7,6,5,4]
30, 30, 20,20 = 100


difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
[(99,57), (66,47), (24,85)]
   ---     ---       ----
[40,25,25]

0 
*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int jsize = difficulty.size();
        int total = 0; 
        vector<vector<int>> v (jsize, vector<int>(2, 0)); 
        for (int i = 0 ; i < jsize; i++){
            v[i][0] = profit[i]; 
            v[i][1] = difficulty[i]; 
        }
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());

        int j = worker.size()-1 ;
        for (int i = jsize-1 ; i >= 0; i--){
            while(v[i][1] <= worker[j]){
                j--;
                total += v[i][0];
                if (j < 0) return total;
            }
        }
        return total; 
    }
};
