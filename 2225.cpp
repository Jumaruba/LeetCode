#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std; 


/*

matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
1 - not lost
2 - lost just one 
players = {1,2,3,...}
wins: {1:1, 2:1, 3:1, 5:1}...
losses: {3:2, 6:2}...

for all players, check if the win all and if they have exactly one loss. 
*/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        vector<int> win_all; 
        vector<int> lost_one; 

        unordered_map<int, int> loss; 
        unordered_map<int, int> win; 

        for (vector<int> match: matches) {
            loss[match[1]] ++; 
            win[match[0]] ++;
        }
        
        // compute only win.
        for (auto it: win)
            if (loss.find(it.first) == loss.end()) win_all.push_back(it.first);
        // compute only loss.
        for (auto it: loss) 
            if (it.second == 1)  lost_one.push_back(it.first);
        
        sort(win_all.begin(), win_all.end());
        sort(lost_one.begin(), lost_one.end());
        ans.push_back(win_all);
        ans.push_back(lost_one);
        return ans;
    }
};